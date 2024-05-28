// C++/WinRT v2.0.220110.5

/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
  *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with ITGSS, 640 N McCarvy Blvd. in the
 * city of Milpitas, zip code 95035, state of California.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

// About:
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Thursday, May 23, 2024
// Technology: C++20 - ISO/IEC 14882:2020(E) 
//

#pragma once
#ifndef LLM_OS_System_H
#define LLM_OS_System_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.ApplicationModel.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.Storage.Search.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.System.Diagnostics.2.h"
#include "llm/impl/Windows.System.RemoteSystems.2.h"
#include "llm/impl/Windows.UI.Popups.2.h"
#include "llm/impl/Windows.UI.ViewManagement.2.h"
#include "llm/impl/Windows.System.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_System_IAppActivationResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppActivationResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::AppResourceGroupInfo) consume_Windows_System_IAppActivationResult<D>::AppResourceGroupInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppActivationResult)->get_AppResourceGroupInfo(&value));
        return llm::OS::System::AppResourceGroupInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppInfo) consume_Windows_System_IAppDiagnosticInfo<D>::AppInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppDiagnosticInfo)->get_AppInfo(&value));
        return llm::OS::ApplicationModel::AppInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::System::AppResourceGroupInfo>) consume_Windows_System_IAppDiagnosticInfo2<D>::GetResourceGroups() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppDiagnosticInfo2)->GetResourceGroups(&result));
        return llm::OS::Foundation::Collections::IVector<llm::OS::System::AppResourceGroupInfo>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::AppResourceGroupInfoWatcher) consume_Windows_System_IAppDiagnosticInfo2<D>::CreateResourceGroupWatcher() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppDiagnosticInfo2)->CreateResourceGroupWatcher(&result));
        return llm::OS::System::AppResourceGroupInfoWatcher{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::AppActivationResult>) consume_Windows_System_IAppDiagnosticInfo3<D>::LaunchAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppDiagnosticInfo3)->LaunchAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::AppActivationResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::System::AppDiagnosticInfo>>) consume_Windows_System_IAppDiagnosticInfoStatics<D>::RequestInfoAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppDiagnosticInfoStatics)->RequestInfoAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::System::AppDiagnosticInfo>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::AppDiagnosticInfoWatcher) consume_Windows_System_IAppDiagnosticInfoStatics2<D>::CreateWatcher() const
    {
        void* watcher{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppDiagnosticInfoStatics2)->CreateWatcher(&watcher));
        return llm::OS::System::AppDiagnosticInfoWatcher{ watcher, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::DiagnosticAccessStatus>) consume_Windows_System_IAppDiagnosticInfoStatics2<D>::RequestAccessAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppDiagnosticInfoStatics2)->RequestAccessAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::DiagnosticAccessStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::System::AppDiagnosticInfo>>) consume_Windows_System_IAppDiagnosticInfoStatics2<D>::RequestInfoForPackageAsync(param::hstring const& packageFamilyName) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppDiagnosticInfoStatics2)->RequestInfoForPackageAsync(*(void**)(&packageFamilyName), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::System::AppDiagnosticInfo>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::System::AppDiagnosticInfo>>) consume_Windows_System_IAppDiagnosticInfoStatics2<D>::RequestInfoForAppAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppDiagnosticInfoStatics2)->RequestInfoForAppAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::System::AppDiagnosticInfo>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::System::AppDiagnosticInfo>>) consume_Windows_System_IAppDiagnosticInfoStatics2<D>::RequestInfoForAppAsync(param::hstring const& appUserModelId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppDiagnosticInfoStatics2)->RequestInfoForAppUserModelId(*(void**)(&appUserModelId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::System::AppDiagnosticInfo>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_IAppDiagnosticInfoWatcher<D>::Added(llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppDiagnosticInfoWatcher, llm::OS::System::AppDiagnosticInfoWatcherEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppDiagnosticInfoWatcher)->add_Added(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_IAppDiagnosticInfoWatcher<D>::Added_revoker consume_Windows_System_IAppDiagnosticInfoWatcher<D>::Added(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppDiagnosticInfoWatcher, llm::OS::System::AppDiagnosticInfoWatcherEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Added_revoker>(this, Added(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IAppDiagnosticInfoWatcher<D>::Added(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::IAppDiagnosticInfoWatcher)->remove_Added(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_IAppDiagnosticInfoWatcher<D>::Removed(llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppDiagnosticInfoWatcher, llm::OS::System::AppDiagnosticInfoWatcherEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppDiagnosticInfoWatcher)->add_Removed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_IAppDiagnosticInfoWatcher<D>::Removed_revoker consume_Windows_System_IAppDiagnosticInfoWatcher<D>::Removed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppDiagnosticInfoWatcher, llm::OS::System::AppDiagnosticInfoWatcherEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Removed_revoker>(this, Removed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IAppDiagnosticInfoWatcher<D>::Removed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::IAppDiagnosticInfoWatcher)->remove_Removed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_IAppDiagnosticInfoWatcher<D>::EnumerationCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppDiagnosticInfoWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppDiagnosticInfoWatcher)->add_EnumerationCompleted(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_IAppDiagnosticInfoWatcher<D>::EnumerationCompleted_revoker consume_Windows_System_IAppDiagnosticInfoWatcher<D>::EnumerationCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppDiagnosticInfoWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, EnumerationCompleted_revoker>(this, EnumerationCompleted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IAppDiagnosticInfoWatcher<D>::EnumerationCompleted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::IAppDiagnosticInfoWatcher)->remove_EnumerationCompleted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_IAppDiagnosticInfoWatcher<D>::Stopped(llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppDiagnosticInfoWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppDiagnosticInfoWatcher)->add_Stopped(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_IAppDiagnosticInfoWatcher<D>::Stopped_revoker consume_Windows_System_IAppDiagnosticInfoWatcher<D>::Stopped(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppDiagnosticInfoWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, Stopped_revoker>(this, Stopped(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IAppDiagnosticInfoWatcher<D>::Stopped(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::IAppDiagnosticInfoWatcher)->remove_Stopped(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::AppDiagnosticInfoWatcherStatus) consume_Windows_System_IAppDiagnosticInfoWatcher<D>::Status() const
    {
        llm::OS::System::AppDiagnosticInfoWatcherStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppDiagnosticInfoWatcher)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IAppDiagnosticInfoWatcher<D>::Start() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppDiagnosticInfoWatcher)->Start());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IAppDiagnosticInfoWatcher<D>::Stop() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppDiagnosticInfoWatcher)->Stop());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::AppDiagnosticInfo) consume_Windows_System_IAppDiagnosticInfoWatcherEventArgs<D>::AppDiagnosticInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppDiagnosticInfoWatcherEventArgs)->get_AppDiagnosticInfo(&value));
        return llm::OS::System::AppDiagnosticInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_System_IAppExecutionStateChangeResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppExecutionStateChangeResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_IAppMemoryReport<D>::PrivateCommitUsage() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppMemoryReport)->get_PrivateCommitUsage(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_IAppMemoryReport<D>::PeakPrivateCommitUsage() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppMemoryReport)->get_PeakPrivateCommitUsage(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_IAppMemoryReport<D>::TotalCommitUsage() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppMemoryReport)->get_TotalCommitUsage(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_IAppMemoryReport<D>::TotalCommitLimit() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppMemoryReport)->get_TotalCommitLimit(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_IAppMemoryReport2<D>::ExpectedTotalCommitLimit() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppMemoryReport2)->get_ExpectedTotalCommitLimit(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_IAppMemoryUsageLimitChangingEventArgs<D>::OldLimit() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppMemoryUsageLimitChangingEventArgs)->get_OldLimit(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_IAppMemoryUsageLimitChangingEventArgs<D>::NewLimit() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppMemoryUsageLimitChangingEventArgs)->get_NewLimit(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_System_IAppResourceGroupBackgroundTaskReport<D>::TaskId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupBackgroundTaskReport)->get_TaskId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_IAppResourceGroupBackgroundTaskReport<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupBackgroundTaskReport)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_IAppResourceGroupBackgroundTaskReport<D>::Trigger() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupBackgroundTaskReport)->get_Trigger(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_IAppResourceGroupBackgroundTaskReport<D>::EntryPoint() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupBackgroundTaskReport)->get_EntryPoint(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_System_IAppResourceGroupInfo<D>::InstanceId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfo)->get_InstanceId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_IAppResourceGroupInfo<D>::IsShared() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfo)->get_IsShared(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::System::AppResourceGroupBackgroundTaskReport>) consume_Windows_System_IAppResourceGroupInfo<D>::GetBackgroundTaskReports() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfo)->GetBackgroundTaskReports(&result));
        return llm::OS::Foundation::Collections::IVector<llm::OS::System::AppResourceGroupBackgroundTaskReport>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::AppResourceGroupMemoryReport) consume_Windows_System_IAppResourceGroupInfo<D>::GetMemoryReport() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfo)->GetMemoryReport(&result));
        return llm::OS::System::AppResourceGroupMemoryReport{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::System::Diagnostics::ProcessDiagnosticInfo>) consume_Windows_System_IAppResourceGroupInfo<D>::GetProcessDiagnosticInfos() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfo)->GetProcessDiagnosticInfos(&result));
        return llm::OS::Foundation::Collections::IVector<llm::OS::System::Diagnostics::ProcessDiagnosticInfo>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::AppResourceGroupStateReport) consume_Windows_System_IAppResourceGroupInfo<D>::GetStateReport() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfo)->GetStateReport(&result));
        return llm::OS::System::AppResourceGroupStateReport{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::AppExecutionStateChangeResult>) consume_Windows_System_IAppResourceGroupInfo2<D>::StartSuspendAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfo2)->StartSuspendAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::AppExecutionStateChangeResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::AppExecutionStateChangeResult>) consume_Windows_System_IAppResourceGroupInfo2<D>::StartResumeAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfo2)->StartResumeAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::AppExecutionStateChangeResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::AppExecutionStateChangeResult>) consume_Windows_System_IAppResourceGroupInfo2<D>::StartTerminateAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfo2)->StartTerminateAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::AppExecutionStateChangeResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_IAppResourceGroupInfoWatcher<D>::Added(llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppResourceGroupInfoWatcher, llm::OS::System::AppResourceGroupInfoWatcherEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfoWatcher)->add_Added(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_IAppResourceGroupInfoWatcher<D>::Added_revoker consume_Windows_System_IAppResourceGroupInfoWatcher<D>::Added(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppResourceGroupInfoWatcher, llm::OS::System::AppResourceGroupInfoWatcherEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Added_revoker>(this, Added(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IAppResourceGroupInfoWatcher<D>::Added(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfoWatcher)->remove_Added(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_IAppResourceGroupInfoWatcher<D>::Removed(llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppResourceGroupInfoWatcher, llm::OS::System::AppResourceGroupInfoWatcherEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfoWatcher)->add_Removed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_IAppResourceGroupInfoWatcher<D>::Removed_revoker consume_Windows_System_IAppResourceGroupInfoWatcher<D>::Removed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppResourceGroupInfoWatcher, llm::OS::System::AppResourceGroupInfoWatcherEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Removed_revoker>(this, Removed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IAppResourceGroupInfoWatcher<D>::Removed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfoWatcher)->remove_Removed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_IAppResourceGroupInfoWatcher<D>::EnumerationCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppResourceGroupInfoWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfoWatcher)->add_EnumerationCompleted(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_IAppResourceGroupInfoWatcher<D>::EnumerationCompleted_revoker consume_Windows_System_IAppResourceGroupInfoWatcher<D>::EnumerationCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppResourceGroupInfoWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, EnumerationCompleted_revoker>(this, EnumerationCompleted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IAppResourceGroupInfoWatcher<D>::EnumerationCompleted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfoWatcher)->remove_EnumerationCompleted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_IAppResourceGroupInfoWatcher<D>::Stopped(llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppResourceGroupInfoWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfoWatcher)->add_Stopped(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_IAppResourceGroupInfoWatcher<D>::Stopped_revoker consume_Windows_System_IAppResourceGroupInfoWatcher<D>::Stopped(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppResourceGroupInfoWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, Stopped_revoker>(this, Stopped(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IAppResourceGroupInfoWatcher<D>::Stopped(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfoWatcher)->remove_Stopped(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_IAppResourceGroupInfoWatcher<D>::ExecutionStateChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppResourceGroupInfoWatcher, llm::OS::System::AppResourceGroupInfoWatcherExecutionStateChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfoWatcher)->add_ExecutionStateChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_IAppResourceGroupInfoWatcher<D>::ExecutionStateChanged_revoker consume_Windows_System_IAppResourceGroupInfoWatcher<D>::ExecutionStateChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppResourceGroupInfoWatcher, llm::OS::System::AppResourceGroupInfoWatcherExecutionStateChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ExecutionStateChanged_revoker>(this, ExecutionStateChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IAppResourceGroupInfoWatcher<D>::ExecutionStateChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfoWatcher)->remove_ExecutionStateChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::AppResourceGroupInfoWatcherStatus) consume_Windows_System_IAppResourceGroupInfoWatcher<D>::Status() const
    {
        llm::OS::System::AppResourceGroupInfoWatcherStatus status{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfoWatcher)->get_Status(reinterpret_cast<int32_t*>(&status)));
        return status;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IAppResourceGroupInfoWatcher<D>::Start() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfoWatcher)->Start());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IAppResourceGroupInfoWatcher<D>::Stop() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfoWatcher)->Stop());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::System::AppDiagnosticInfo>) consume_Windows_System_IAppResourceGroupInfoWatcherEventArgs<D>::AppDiagnosticInfos() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfoWatcherEventArgs)->get_AppDiagnosticInfos(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::System::AppDiagnosticInfo>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::AppResourceGroupInfo) consume_Windows_System_IAppResourceGroupInfoWatcherEventArgs<D>::AppResourceGroupInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfoWatcherEventArgs)->get_AppResourceGroupInfo(&value));
        return llm::OS::System::AppResourceGroupInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::System::AppDiagnosticInfo>) consume_Windows_System_IAppResourceGroupInfoWatcherExecutionStateChangedEventArgs<D>::AppDiagnosticInfos() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfoWatcherExecutionStateChangedEventArgs)->get_AppDiagnosticInfos(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::System::AppDiagnosticInfo>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::AppResourceGroupInfo) consume_Windows_System_IAppResourceGroupInfoWatcherExecutionStateChangedEventArgs<D>::AppResourceGroupInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupInfoWatcherExecutionStateChangedEventArgs)->get_AppResourceGroupInfo(&value));
        return llm::OS::System::AppResourceGroupInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_IAppResourceGroupMemoryReport<D>::CommitUsageLimit() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupMemoryReport)->get_CommitUsageLimit(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::AppMemoryUsageLevel) consume_Windows_System_IAppResourceGroupMemoryReport<D>::CommitUsageLevel() const
    {
        llm::OS::System::AppMemoryUsageLevel value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupMemoryReport)->get_CommitUsageLevel(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_IAppResourceGroupMemoryReport<D>::PrivateCommitUsage() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupMemoryReport)->get_PrivateCommitUsage(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_IAppResourceGroupMemoryReport<D>::TotalCommitUsage() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupMemoryReport)->get_TotalCommitUsage(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::AppResourceGroupExecutionState) consume_Windows_System_IAppResourceGroupStateReport<D>::ExecutionState() const
    {
        llm::OS::System::AppResourceGroupExecutionState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupStateReport)->get_ExecutionState(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::AppResourceGroupEnergyQuotaState) consume_Windows_System_IAppResourceGroupStateReport<D>::EnergyQuotaState() const
    {
        llm::OS::System::AppResourceGroupEnergyQuotaState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppResourceGroupStateReport)->get_EnergyQuotaState(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_IAppUriHandlerHost<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppUriHandlerHost)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IAppUriHandlerHost<D>::Name(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppUriHandlerHost)->put_Name(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_IAppUriHandlerHost2<D>::IsEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppUriHandlerHost2)->get_IsEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IAppUriHandlerHost2<D>::IsEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppUriHandlerHost2)->put_IsEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::AppUriHandlerHost) consume_Windows_System_IAppUriHandlerHostFactory<D>::CreateInstance(param::hstring const& name) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppUriHandlerHostFactory)->CreateInstance(*(void**)(&name), &value));
        return llm::OS::System::AppUriHandlerHost{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_IAppUriHandlerRegistration<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppUriHandlerRegistration)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_System_IAppUriHandlerRegistration<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppUriHandlerRegistration)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::System::AppUriHandlerHost>>) consume_Windows_System_IAppUriHandlerRegistration<D>::GetAppAddedHostsAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppUriHandlerRegistration)->GetAppAddedHostsAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::System::AppUriHandlerHost>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_System_IAppUriHandlerRegistration<D>::SetAppAddedHostsAsync(param::async_iterable<llm::OS::System::AppUriHandlerHost> const& hosts) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppUriHandlerRegistration)->SetAppAddedHostsAsync(*(void**)(&hosts), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::System::AppUriHandlerHost>) consume_Windows_System_IAppUriHandlerRegistration2<D>::GetAllHosts() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppUriHandlerRegistration2)->GetAllHosts(&result));
        return llm::OS::Foundation::Collections::IVector<llm::OS::System::AppUriHandlerHost>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IAppUriHandlerRegistration2<D>::UpdateHosts(param::iterable<llm::OS::System::AppUriHandlerHost> const& hosts) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppUriHandlerRegistration2)->UpdateHosts(*(void**)(&hosts)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_IAppUriHandlerRegistration2<D>::PackageFamilyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppUriHandlerRegistration2)->get_PackageFamilyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_System_IAppUriHandlerRegistrationManager<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppUriHandlerRegistrationManager)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::AppUriHandlerRegistration) consume_Windows_System_IAppUriHandlerRegistrationManager<D>::TryGetRegistration(param::hstring const& name) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppUriHandlerRegistrationManager)->TryGetRegistration(*(void**)(&name), &result));
        return llm::OS::System::AppUriHandlerRegistration{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_IAppUriHandlerRegistrationManager2<D>::PackageFamilyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppUriHandlerRegistrationManager2)->get_PackageFamilyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::AppUriHandlerRegistrationManager) consume_Windows_System_IAppUriHandlerRegistrationManagerStatics<D>::GetDefault() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppUriHandlerRegistrationManagerStatics)->GetDefault(&result));
        return llm::OS::System::AppUriHandlerRegistrationManager{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::AppUriHandlerRegistrationManager) consume_Windows_System_IAppUriHandlerRegistrationManagerStatics<D>::GetForUser(llm::OS::System::User const& user) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppUriHandlerRegistrationManagerStatics)->GetForUser(*(void**)(&user), &result));
        return llm::OS::System::AppUriHandlerRegistrationManager{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::AppUriHandlerRegistrationManager) consume_Windows_System_IAppUriHandlerRegistrationManagerStatics2<D>::GetForPackage(param::hstring const& packageFamilyName) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppUriHandlerRegistrationManagerStatics2)->GetForPackage(*(void**)(&packageFamilyName), &result));
        return llm::OS::System::AppUriHandlerRegistrationManager{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::AppUriHandlerRegistrationManager) consume_Windows_System_IAppUriHandlerRegistrationManagerStatics2<D>::GetForPackageForUser(param::hstring const& packageFamilyName, llm::OS::System::User const& user) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IAppUriHandlerRegistrationManagerStatics2)->GetForPackageForUser(*(void**)(&packageFamilyName), *(void**)(&user), &result));
        return llm::OS::System::AppUriHandlerRegistrationManager{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IDateTimeSettingsStatics<D>::SetSystemDateTime(llm::OS::Foundation::DateTime const& utcDateTime) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IDateTimeSettingsStatics)->SetSystemDateTime(impl::bind_in(utcDateTime)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::DispatcherQueueTimer) consume_Windows_System_IDispatcherQueue<D>::CreateTimer() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IDispatcherQueue)->CreateTimer(&result));
        return llm::OS::System::DispatcherQueueTimer{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_IDispatcherQueue<D>::TryEnqueue(llm::OS::System::DispatcherQueueHandler const& callback) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IDispatcherQueue)->TryEnqueue(*(void**)(&callback), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_IDispatcherQueue<D>::TryEnqueue(llm::OS::System::DispatcherQueuePriority const& priority, llm::OS::System::DispatcherQueueHandler const& callback) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IDispatcherQueue)->TryEnqueueWithPriority(static_cast<int32_t>(priority), *(void**)(&callback), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_IDispatcherQueue<D>::ShutdownStarting(llm::OS::Foundation::TypedEventHandler<llm::OS::System::DispatcherQueue, llm::OS::System::DispatcherQueueShutdownStartingEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IDispatcherQueue)->add_ShutdownStarting(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_IDispatcherQueue<D>::ShutdownStarting_revoker consume_Windows_System_IDispatcherQueue<D>::ShutdownStarting(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::DispatcherQueue, llm::OS::System::DispatcherQueueShutdownStartingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ShutdownStarting_revoker>(this, ShutdownStarting(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IDispatcherQueue<D>::ShutdownStarting(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::IDispatcherQueue)->remove_ShutdownStarting(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_IDispatcherQueue<D>::ShutdownCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::System::DispatcherQueue, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IDispatcherQueue)->add_ShutdownCompleted(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_IDispatcherQueue<D>::ShutdownCompleted_revoker consume_Windows_System_IDispatcherQueue<D>::ShutdownCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::DispatcherQueue, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, ShutdownCompleted_revoker>(this, ShutdownCompleted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IDispatcherQueue<D>::ShutdownCompleted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::IDispatcherQueue)->remove_ShutdownCompleted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_IDispatcherQueue2<D>::HasThreadAccess() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IDispatcherQueue2)->get_HasThreadAccess(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::DispatcherQueue) consume_Windows_System_IDispatcherQueueController<D>::DispatcherQueue() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IDispatcherQueueController)->get_DispatcherQueue(&value));
        return llm::OS::System::DispatcherQueue{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_System_IDispatcherQueueController<D>::ShutdownQueueAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IDispatcherQueueController)->ShutdownQueueAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::DispatcherQueueController) consume_Windows_System_IDispatcherQueueControllerStatics<D>::CreateOnDedicatedThread() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IDispatcherQueueControllerStatics)->CreateOnDedicatedThread(&result));
        return llm::OS::System::DispatcherQueueController{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_System_IDispatcherQueueShutdownStartingEventArgs<D>::GetDeferral() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IDispatcherQueueShutdownStartingEventArgs)->GetDeferral(&result));
        return llm::OS::Foundation::Deferral{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::DispatcherQueue) consume_Windows_System_IDispatcherQueueStatics<D>::GetForCurrentThread() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IDispatcherQueueStatics)->GetForCurrentThread(&result));
        return llm::OS::System::DispatcherQueue{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_System_IDispatcherQueueTimer<D>::Interval() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IDispatcherQueueTimer)->get_Interval(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IDispatcherQueueTimer<D>::Interval(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IDispatcherQueueTimer)->put_Interval(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_IDispatcherQueueTimer<D>::IsRunning() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IDispatcherQueueTimer)->get_IsRunning(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_IDispatcherQueueTimer<D>::IsRepeating() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IDispatcherQueueTimer)->get_IsRepeating(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IDispatcherQueueTimer<D>::IsRepeating(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IDispatcherQueueTimer)->put_IsRepeating(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IDispatcherQueueTimer<D>::Start() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IDispatcherQueueTimer)->Start());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IDispatcherQueueTimer<D>::Stop() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IDispatcherQueueTimer)->Stop());
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_IDispatcherQueueTimer<D>::Tick(llm::OS::Foundation::TypedEventHandler<llm::OS::System::DispatcherQueueTimer, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IDispatcherQueueTimer)->add_Tick(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_IDispatcherQueueTimer<D>::Tick_revoker consume_Windows_System_IDispatcherQueueTimer<D>::Tick(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::DispatcherQueueTimer, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, Tick_revoker>(this, Tick(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IDispatcherQueueTimer<D>::Tick(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::IDispatcherQueueTimer)->remove_Tick(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Storage::IStorageItem>) consume_Windows_System_IFolderLauncherOptions<D>::ItemsToSelect() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IFolderLauncherOptions)->get_ItemsToSelect(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Storage::IStorageItem>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_IKnownUserPropertiesStatics<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IKnownUserPropertiesStatics)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_IKnownUserPropertiesStatics<D>::FirstName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IKnownUserPropertiesStatics)->get_FirstName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_IKnownUserPropertiesStatics<D>::LastName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IKnownUserPropertiesStatics)->get_LastName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_IKnownUserPropertiesStatics<D>::ProviderName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IKnownUserPropertiesStatics)->get_ProviderName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_IKnownUserPropertiesStatics<D>::AccountName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IKnownUserPropertiesStatics)->get_AccountName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_IKnownUserPropertiesStatics<D>::GuestHost() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IKnownUserPropertiesStatics)->get_GuestHost(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_IKnownUserPropertiesStatics<D>::PrincipalName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IKnownUserPropertiesStatics)->get_PrincipalName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_IKnownUserPropertiesStatics<D>::DomainName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IKnownUserPropertiesStatics)->get_DomainName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_IKnownUserPropertiesStatics<D>::SessionInitiationProtocolUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IKnownUserPropertiesStatics)->get_SessionInitiationProtocolUri(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_IKnownUserPropertiesStatics2<D>::AgeEnforcementRegion() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IKnownUserPropertiesStatics2)->get_AgeEnforcementRegion(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::LaunchUriStatus) consume_Windows_System_ILaunchUriResult<D>::Status() const
    {
        llm::OS::System::LaunchUriStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILaunchUriResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::ValueSet) consume_Windows_System_ILaunchUriResult<D>::Result() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILaunchUriResult)->get_Result(&value));
        return llm::OS::Foundation::Collections::ValueSet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_ILauncherOptions<D>::TreatAsUntrusted() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherOptions)->get_TreatAsUntrusted(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_ILauncherOptions<D>::TreatAsUntrusted(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherOptions)->put_TreatAsUntrusted(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_ILauncherOptions<D>::DisplayApplicationPicker() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherOptions)->get_DisplayApplicationPicker(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_ILauncherOptions<D>::DisplayApplicationPicker(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherOptions)->put_DisplayApplicationPicker(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::LauncherUIOptions) consume_Windows_System_ILauncherOptions<D>::UI() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherOptions)->get_UI(&value));
        return llm::OS::System::LauncherUIOptions{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_ILauncherOptions<D>::PreferredApplicationPackageFamilyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherOptions)->get_PreferredApplicationPackageFamilyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_ILauncherOptions<D>::PreferredApplicationPackageFamilyName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherOptions)->put_PreferredApplicationPackageFamilyName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_ILauncherOptions<D>::PreferredApplicationDisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherOptions)->get_PreferredApplicationDisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_ILauncherOptions<D>::PreferredApplicationDisplayName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherOptions)->put_PreferredApplicationDisplayName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_System_ILauncherOptions<D>::FallbackUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherOptions)->get_FallbackUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_ILauncherOptions<D>::FallbackUri(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherOptions)->put_FallbackUri(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_ILauncherOptions<D>::ContentType() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherOptions)->get_ContentType(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_ILauncherOptions<D>::ContentType(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherOptions)->put_ContentType(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_ILauncherOptions2<D>::TargetApplicationPackageFamilyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherOptions2)->get_TargetApplicationPackageFamilyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_ILauncherOptions2<D>::TargetApplicationPackageFamilyName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherOptions2)->put_TargetApplicationPackageFamilyName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Search::StorageFileQueryResult) consume_Windows_System_ILauncherOptions2<D>::NeighboringFilesQuery() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherOptions2)->get_NeighboringFilesQuery(&value));
        return llm::OS::Storage::Search::StorageFileQueryResult{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_ILauncherOptions2<D>::NeighboringFilesQuery(llm::OS::Storage::Search::StorageFileQueryResult const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherOptions2)->put_NeighboringFilesQuery(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_ILauncherOptions3<D>::IgnoreAppUriHandlers() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherOptions3)->get_IgnoreAppUriHandlers(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_ILauncherOptions3<D>::IgnoreAppUriHandlers(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherOptions3)->put_IgnoreAppUriHandlers(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_ILauncherOptions4<D>::LimitPickerToCurrentAppAndAppUriHandlers() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherOptions4)->get_LimitPickerToCurrentAppAndAppUriHandlers(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_ILauncherOptions4<D>::LimitPickerToCurrentAppAndAppUriHandlers(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherOptions4)->put_LimitPickerToCurrentAppAndAppUriHandlers(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_System_ILauncherStatics<D>::LaunchFileAsync(llm::OS::Storage::IStorageFile const& file) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics)->LaunchFileAsync(*(void**)(&file), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_System_ILauncherStatics<D>::LaunchFileAsync(llm::OS::Storage::IStorageFile const& file, llm::OS::System::LauncherOptions const& options) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics)->LaunchFileWithOptionsAsync(*(void**)(&file), *(void**)(&options), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_System_ILauncherStatics<D>::LaunchUriAsync(llm::OS::Foundation::Uri const& uri) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics)->LaunchUriAsync(*(void**)(&uri), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_System_ILauncherStatics<D>::LaunchUriAsync(llm::OS::Foundation::Uri const& uri, llm::OS::System::LauncherOptions const& options) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics)->LaunchUriWithOptionsAsync(*(void**)(&uri), *(void**)(&options), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchUriResult>) consume_Windows_System_ILauncherStatics2<D>::LaunchUriForResultsAsync(llm::OS::Foundation::Uri const& uri, llm::OS::System::LauncherOptions const& options) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics2)->LaunchUriForResultsAsync(*(void**)(&uri), *(void**)(&options), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchUriResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchUriResult>) consume_Windows_System_ILauncherStatics2<D>::LaunchUriForResultsAsync(llm::OS::Foundation::Uri const& uri, llm::OS::System::LauncherOptions const& options, llm::OS::Foundation::Collections::ValueSet const& inputData) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics2)->LaunchUriForResultsWithDataAsync(*(void**)(&uri), *(void**)(&options), *(void**)(&inputData), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchUriResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_System_ILauncherStatics2<D>::LaunchUriAsync(llm::OS::Foundation::Uri const& uri, llm::OS::System::LauncherOptions const& options, llm::OS::Foundation::Collections::ValueSet const& inputData) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics2)->LaunchUriWithDataAsync(*(void**)(&uri), *(void**)(&options), *(void**)(&inputData), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchQuerySupportStatus>) consume_Windows_System_ILauncherStatics2<D>::QueryUriSupportAsync(llm::OS::Foundation::Uri const& uri, llm::OS::System::LaunchQuerySupportType const& launchQuerySupportType) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics2)->QueryUriSupportAsync(*(void**)(&uri), static_cast<int32_t>(launchQuerySupportType), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchQuerySupportStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchQuerySupportStatus>) consume_Windows_System_ILauncherStatics2<D>::QueryUriSupportAsync(llm::OS::Foundation::Uri const& uri, llm::OS::System::LaunchQuerySupportType const& launchQuerySupportType, param::hstring const& packageFamilyName) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics2)->QueryUriSupportWithPackageFamilyNameAsync(*(void**)(&uri), static_cast<int32_t>(launchQuerySupportType), *(void**)(&packageFamilyName), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchQuerySupportStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchQuerySupportStatus>) consume_Windows_System_ILauncherStatics2<D>::QueryFileSupportAsync(llm::OS::Storage::StorageFile const& file) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics2)->QueryFileSupportAsync(*(void**)(&file), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchQuerySupportStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchQuerySupportStatus>) consume_Windows_System_ILauncherStatics2<D>::QueryFileSupportAsync(llm::OS::Storage::StorageFile const& file, param::hstring const& packageFamilyName) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics2)->QueryFileSupportWithPackageFamilyNameAsync(*(void**)(&file), *(void**)(&packageFamilyName), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchQuerySupportStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppInfo>>) consume_Windows_System_ILauncherStatics2<D>::FindUriSchemeHandlersAsync(param::hstring const& scheme) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics2)->FindUriSchemeHandlersAsync(*(void**)(&scheme), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppInfo>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppInfo>>) consume_Windows_System_ILauncherStatics2<D>::FindUriSchemeHandlersAsync(param::hstring const& scheme, llm::OS::System::LaunchQuerySupportType const& launchQuerySupportType) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics2)->FindUriSchemeHandlersWithLaunchUriTypeAsync(*(void**)(&scheme), static_cast<int32_t>(launchQuerySupportType), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppInfo>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppInfo>>) consume_Windows_System_ILauncherStatics2<D>::FindFileHandlersAsync(param::hstring const& extension) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics2)->FindFileHandlersAsync(*(void**)(&extension), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppInfo>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_System_ILauncherStatics3<D>::LaunchFolderAsync(llm::OS::Storage::IStorageFolder const& folder) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics3)->LaunchFolderAsync(*(void**)(&folder), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_System_ILauncherStatics3<D>::LaunchFolderAsync(llm::OS::Storage::IStorageFolder const& folder, llm::OS::System::FolderLauncherOptions const& options) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics3)->LaunchFolderWithOptionsAsync(*(void**)(&folder), *(void**)(&options), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchQuerySupportStatus>) consume_Windows_System_ILauncherStatics4<D>::QueryAppUriSupportAsync(llm::OS::Foundation::Uri const& uri) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics4)->QueryAppUriSupportAsync(*(void**)(&uri), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchQuerySupportStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchQuerySupportStatus>) consume_Windows_System_ILauncherStatics4<D>::QueryAppUriSupportAsync(llm::OS::Foundation::Uri const& uri, param::hstring const& packageFamilyName) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics4)->QueryAppUriSupportWithPackageFamilyNameAsync(*(void**)(&uri), *(void**)(&packageFamilyName), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchQuerySupportStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppInfo>>) consume_Windows_System_ILauncherStatics4<D>::FindAppUriHandlersAsync(llm::OS::Foundation::Uri const& uri) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics4)->FindAppUriHandlersAsync(*(void**)(&uri), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppInfo>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchUriStatus>) consume_Windows_System_ILauncherStatics4<D>::LaunchUriForUserAsync(llm::OS::System::User const& user, llm::OS::Foundation::Uri const& uri) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics4)->LaunchUriForUserAsync(*(void**)(&user), *(void**)(&uri), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchUriStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchUriStatus>) consume_Windows_System_ILauncherStatics4<D>::LaunchUriForUserAsync(llm::OS::System::User const& user, llm::OS::Foundation::Uri const& uri, llm::OS::System::LauncherOptions const& options) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics4)->LaunchUriWithOptionsForUserAsync(*(void**)(&user), *(void**)(&uri), *(void**)(&options), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchUriStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchUriStatus>) consume_Windows_System_ILauncherStatics4<D>::LaunchUriForUserAsync(llm::OS::System::User const& user, llm::OS::Foundation::Uri const& uri, llm::OS::System::LauncherOptions const& options, llm::OS::Foundation::Collections::ValueSet const& inputData) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics4)->LaunchUriWithDataForUserAsync(*(void**)(&user), *(void**)(&uri), *(void**)(&options), *(void**)(&inputData), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchUriStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchUriResult>) consume_Windows_System_ILauncherStatics4<D>::LaunchUriForResultsForUserAsync(llm::OS::System::User const& user, llm::OS::Foundation::Uri const& uri, llm::OS::System::LauncherOptions const& options) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics4)->LaunchUriForResultsForUserAsync(*(void**)(&user), *(void**)(&uri), *(void**)(&options), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchUriResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchUriResult>) consume_Windows_System_ILauncherStatics4<D>::LaunchUriForResultsForUserAsync(llm::OS::System::User const& user, llm::OS::Foundation::Uri const& uri, llm::OS::System::LauncherOptions const& options, llm::OS::Foundation::Collections::ValueSet const& inputData) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics4)->LaunchUriForResultsWithDataForUserAsync(*(void**)(&user), *(void**)(&uri), *(void**)(&options), *(void**)(&inputData), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchUriResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_System_ILauncherStatics5<D>::LaunchFolderPathAsync(param::hstring const& path) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics5)->LaunchFolderPathAsync(*(void**)(&path), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_System_ILauncherStatics5<D>::LaunchFolderPathAsync(param::hstring const& path, llm::OS::System::FolderLauncherOptions const& options) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics5)->LaunchFolderPathWithOptionsAsync(*(void**)(&path), *(void**)(&options), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_System_ILauncherStatics5<D>::LaunchFolderPathForUserAsync(llm::OS::System::User const& user, param::hstring const& path) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics5)->LaunchFolderPathForUserAsync(*(void**)(&user), *(void**)(&path), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_System_ILauncherStatics5<D>::LaunchFolderPathForUserAsync(llm::OS::System::User const& user, param::hstring const& path, llm::OS::System::FolderLauncherOptions const& options) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherStatics5)->LaunchFolderPathWithOptionsForUserAsync(*(void**)(&user), *(void**)(&path), *(void**)(&options), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::Point>) consume_Windows_System_ILauncherUIOptions<D>::InvocationPoint() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherUIOptions)->get_InvocationPoint(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::Point>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_ILauncherUIOptions<D>::InvocationPoint(llm::OS::Foundation::IReference<llm::OS::Foundation::Point> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherUIOptions)->put_InvocationPoint(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::Rect>) consume_Windows_System_ILauncherUIOptions<D>::SelectionRect() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherUIOptions)->get_SelectionRect(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::Rect>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_ILauncherUIOptions<D>::SelectionRect(llm::OS::Foundation::IReference<llm::OS::Foundation::Rect> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherUIOptions)->put_SelectionRect(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Popups::Placement) consume_Windows_System_ILauncherUIOptions<D>::PreferredPlacement() const
    {
        llm::OS::UI::Popups::Placement value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherUIOptions)->get_PreferredPlacement(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_ILauncherUIOptions<D>::PreferredPlacement(llm::OS::UI::Popups::Placement const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherUIOptions)->put_PreferredPlacement(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::ViewSizePreference) consume_Windows_System_ILauncherViewOptions<D>::DesiredRemainingView() const
    {
        llm::OS::UI::ViewManagement::ViewSizePreference value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherViewOptions)->get_DesiredRemainingView(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_ILauncherViewOptions<D>::DesiredRemainingView(llm::OS::UI::ViewManagement::ViewSizePreference const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ILauncherViewOptions)->put_DesiredRemainingView(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_IMemoryManagerStatics<D>::AppMemoryUsage() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IMemoryManagerStatics)->get_AppMemoryUsage(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_IMemoryManagerStatics<D>::AppMemoryUsageLimit() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IMemoryManagerStatics)->get_AppMemoryUsageLimit(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::AppMemoryUsageLevel) consume_Windows_System_IMemoryManagerStatics<D>::AppMemoryUsageLevel() const
    {
        llm::OS::System::AppMemoryUsageLevel value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IMemoryManagerStatics)->get_AppMemoryUsageLevel(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_IMemoryManagerStatics<D>::AppMemoryUsageIncreased(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IMemoryManagerStatics)->add_AppMemoryUsageIncreased(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_IMemoryManagerStatics<D>::AppMemoryUsageIncreased_revoker consume_Windows_System_IMemoryManagerStatics<D>::AppMemoryUsageIncreased(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, AppMemoryUsageIncreased_revoker>(this, AppMemoryUsageIncreased(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IMemoryManagerStatics<D>::AppMemoryUsageIncreased(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::IMemoryManagerStatics)->remove_AppMemoryUsageIncreased(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_IMemoryManagerStatics<D>::AppMemoryUsageDecreased(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IMemoryManagerStatics)->add_AppMemoryUsageDecreased(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_IMemoryManagerStatics<D>::AppMemoryUsageDecreased_revoker consume_Windows_System_IMemoryManagerStatics<D>::AppMemoryUsageDecreased(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, AppMemoryUsageDecreased_revoker>(this, AppMemoryUsageDecreased(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IMemoryManagerStatics<D>::AppMemoryUsageDecreased(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::IMemoryManagerStatics)->remove_AppMemoryUsageDecreased(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_IMemoryManagerStatics<D>::AppMemoryUsageLimitChanging(llm::OS::Foundation::EventHandler<llm::OS::System::AppMemoryUsageLimitChangingEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IMemoryManagerStatics)->add_AppMemoryUsageLimitChanging(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_IMemoryManagerStatics<D>::AppMemoryUsageLimitChanging_revoker consume_Windows_System_IMemoryManagerStatics<D>::AppMemoryUsageLimitChanging(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::System::AppMemoryUsageLimitChangingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, AppMemoryUsageLimitChanging_revoker>(this, AppMemoryUsageLimitChanging(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IMemoryManagerStatics<D>::AppMemoryUsageLimitChanging(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::IMemoryManagerStatics)->remove_AppMemoryUsageLimitChanging(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::AppMemoryReport) consume_Windows_System_IMemoryManagerStatics2<D>::GetAppMemoryReport() const
    {
        void* memoryReport{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IMemoryManagerStatics2)->GetAppMemoryReport(&memoryReport));
        return llm::OS::System::AppMemoryReport{ memoryReport, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::ProcessMemoryReport) consume_Windows_System_IMemoryManagerStatics2<D>::GetProcessMemoryReport() const
    {
        void* memoryReport{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IMemoryManagerStatics2)->GetProcessMemoryReport(&memoryReport));
        return llm::OS::System::ProcessMemoryReport{ memoryReport, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_IMemoryManagerStatics3<D>::TrySetAppMemoryUsageLimit(uint64_t value) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IMemoryManagerStatics3)->TrySetAppMemoryUsageLimit(value, &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_IMemoryManagerStatics4<D>::ExpectedAppMemoryUsageLimit() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IMemoryManagerStatics4)->get_ExpectedAppMemoryUsageLimit(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IInputStream) consume_Windows_System_IProcessLauncherOptions<D>::StandardInput() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IProcessLauncherOptions)->get_StandardInput(&value));
        return llm::OS::Storage::Streams::IInputStream{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IProcessLauncherOptions<D>::StandardInput(llm::OS::Storage::Streams::IInputStream const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IProcessLauncherOptions)->put_StandardInput(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IOutputStream) consume_Windows_System_IProcessLauncherOptions<D>::StandardOutput() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IProcessLauncherOptions)->get_StandardOutput(&value));
        return llm::OS::Storage::Streams::IOutputStream{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IProcessLauncherOptions<D>::StandardOutput(llm::OS::Storage::Streams::IOutputStream const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IProcessLauncherOptions)->put_StandardOutput(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IOutputStream) consume_Windows_System_IProcessLauncherOptions<D>::StandardError() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IProcessLauncherOptions)->get_StandardError(&value));
        return llm::OS::Storage::Streams::IOutputStream{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IProcessLauncherOptions<D>::StandardError(llm::OS::Storage::Streams::IOutputStream const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IProcessLauncherOptions)->put_StandardError(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_IProcessLauncherOptions<D>::WorkingDirectory() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IProcessLauncherOptions)->get_WorkingDirectory(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IProcessLauncherOptions<D>::WorkingDirectory(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IProcessLauncherOptions)->put_WorkingDirectory(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_System_IProcessLauncherResult<D>::ExitCode() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IProcessLauncherResult)->get_ExitCode(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::ProcessLauncherResult>) consume_Windows_System_IProcessLauncherStatics<D>::RunToCompletionAsync(param::hstring const& fileName, param::hstring const& args) const
    {
        void* asyncOperationResult{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IProcessLauncherStatics)->RunToCompletionAsync(*(void**)(&fileName), *(void**)(&args), &asyncOperationResult));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::ProcessLauncherResult>{ asyncOperationResult, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::ProcessLauncherResult>) consume_Windows_System_IProcessLauncherStatics<D>::RunToCompletionAsync(param::hstring const& fileName, param::hstring const& args, llm::OS::System::ProcessLauncherOptions const& options) const
    {
        void* asyncOperationResult{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IProcessLauncherStatics)->RunToCompletionAsyncWithOptions(*(void**)(&fileName), *(void**)(&args), *(void**)(&options), &asyncOperationResult));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::ProcessLauncherResult>{ asyncOperationResult, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_IProcessMemoryReport<D>::PrivateWorkingSetUsage() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IProcessMemoryReport)->get_PrivateWorkingSetUsage(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_System_IProcessMemoryReport<D>::TotalWorkingSetUsage() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IProcessMemoryReport)->get_TotalWorkingSetUsage(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IProtocolForResultsOperation<D>::ReportCompleted(llm::OS::Foundation::Collections::ValueSet const& data) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IProtocolForResultsOperation)->ReportCompleted(*(void**)(&data)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_System_IRemoteLauncherOptions<D>::FallbackUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IRemoteLauncherOptions)->get_FallbackUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IRemoteLauncherOptions<D>::FallbackUri(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IRemoteLauncherOptions)->put_FallbackUri(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_System_IRemoteLauncherOptions<D>::PreferredAppIds() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IRemoteLauncherOptions)->get_PreferredAppIds(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::RemoteLaunchUriStatus>) consume_Windows_System_IRemoteLauncherStatics<D>::LaunchUriAsync(llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest const& remoteSystemConnectionRequest, llm::OS::Foundation::Uri const& uri) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IRemoteLauncherStatics)->LaunchUriAsync(*(void**)(&remoteSystemConnectionRequest), *(void**)(&uri), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::RemoteLaunchUriStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::RemoteLaunchUriStatus>) consume_Windows_System_IRemoteLauncherStatics<D>::LaunchUriAsync(llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest const& remoteSystemConnectionRequest, llm::OS::Foundation::Uri const& uri, llm::OS::System::RemoteLauncherOptions const& options) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IRemoteLauncherStatics)->LaunchUriWithOptionsAsync(*(void**)(&remoteSystemConnectionRequest), *(void**)(&uri), *(void**)(&options), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::RemoteLaunchUriStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::RemoteLaunchUriStatus>) consume_Windows_System_IRemoteLauncherStatics<D>::LaunchUriAsync(llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest const& remoteSystemConnectionRequest, llm::OS::Foundation::Uri const& uri, llm::OS::System::RemoteLauncherOptions const& options, llm::OS::Foundation::Collections::ValueSet const& inputData) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IRemoteLauncherStatics)->LaunchUriWithDataAsync(*(void**)(&remoteSystemConnectionRequest), *(void**)(&uri), *(void**)(&options), *(void**)(&inputData), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::RemoteLaunchUriStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IShutdownManagerStatics<D>::BeginShutdown(llm::OS::System::ShutdownKind const& shutdownKind, llm::OS::Foundation::TimeSpan const& timeout) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IShutdownManagerStatics)->BeginShutdown(static_cast<int32_t>(shutdownKind), impl::bind_in(timeout)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IShutdownManagerStatics<D>::CancelShutdown() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IShutdownManagerStatics)->CancelShutdown());
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_IShutdownManagerStatics2<D>::IsPowerStateSupported(llm::OS::System::PowerState const& powerState) const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IShutdownManagerStatics2)->IsPowerStateSupported(static_cast<int32_t>(powerState), &value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IShutdownManagerStatics2<D>::EnterPowerState(llm::OS::System::PowerState const& powerState) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IShutdownManagerStatics2)->EnterPowerState(static_cast<int32_t>(powerState)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IShutdownManagerStatics2<D>::EnterPowerState(llm::OS::System::PowerState const& powerState, llm::OS::Foundation::TimeSpan const& wakeUpAfter) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IShutdownManagerStatics2)->EnterPowerStateWithTimeSpan(static_cast<int32_t>(powerState), impl::bind_in(wakeUpAfter)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_ITimeZoneSettingsStatics<D>::CurrentTimeZoneDisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ITimeZoneSettingsStatics)->get_CurrentTimeZoneDisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_System_ITimeZoneSettingsStatics<D>::SupportedTimeZoneDisplayNames() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ITimeZoneSettingsStatics)->get_SupportedTimeZoneDisplayNames(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_ITimeZoneSettingsStatics<D>::CanChangeTimeZone() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ITimeZoneSettingsStatics)->get_CanChangeTimeZone(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_ITimeZoneSettingsStatics<D>::ChangeTimeZoneByDisplayName(param::hstring const& timeZoneDisplayName) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ITimeZoneSettingsStatics)->ChangeTimeZoneByDisplayName(*(void**)(&timeZoneDisplayName)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::AutoUpdateTimeZoneStatus>) consume_Windows_System_ITimeZoneSettingsStatics2<D>::AutoUpdateTimeZoneAsync(llm::OS::Foundation::TimeSpan const& timeout) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::ITimeZoneSettingsStatics2)->AutoUpdateTimeZoneAsync(impl::bind_in(timeout), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::AutoUpdateTimeZoneStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_IUser<D>::NonRoamableId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUser)->get_NonRoamableId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::UserAuthenticationStatus) consume_Windows_System_IUser<D>::AuthenticationStatus() const
    {
        llm::OS::System::UserAuthenticationStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUser)->get_AuthenticationStatus(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::UserType) consume_Windows_System_IUser<D>::Type() const
    {
        llm::OS::System::UserType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUser)->get_Type(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::IInspectable>) consume_Windows_System_IUser<D>::GetPropertyAsync(param::hstring const& value) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUser)->GetPropertyAsync(*(void**)(&value), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::IInspectable>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IPropertySet>) consume_Windows_System_IUser<D>::GetPropertiesAsync(param::async_vector_view<hstring> const& values) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUser)->GetPropertiesAsync(*(void**)(&values), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IPropertySet>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IRandomAccessStreamReference>) consume_Windows_System_IUser<D>::GetPictureAsync(llm::OS::System::UserPictureSize const& desiredSize) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUser)->GetPictureAsync(static_cast<int32_t>(desiredSize), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IRandomAccessStreamReference>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::UserAgeConsentResult>) consume_Windows_System_IUser2<D>::CheckUserAgeConsentGroupAsync(llm::OS::System::UserAgeConsentGroup const& consentGroup) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUser2)->CheckUserAgeConsentGroupAsync(static_cast<int32_t>(consentGroup), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::UserAgeConsentResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IUserAuthenticationStatusChangeDeferral<D>::Complete() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserAuthenticationStatusChangeDeferral)->Complete());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::UserAuthenticationStatusChangeDeferral) consume_Windows_System_IUserAuthenticationStatusChangingEventArgs<D>::GetDeferral() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserAuthenticationStatusChangingEventArgs)->GetDeferral(&result));
        return llm::OS::System::UserAuthenticationStatusChangeDeferral{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_System_IUserAuthenticationStatusChangingEventArgs<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserAuthenticationStatusChangingEventArgs)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::UserAuthenticationStatus) consume_Windows_System_IUserAuthenticationStatusChangingEventArgs<D>::NewStatus() const
    {
        llm::OS::System::UserAuthenticationStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserAuthenticationStatusChangingEventArgs)->get_NewStatus(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::UserAuthenticationStatus) consume_Windows_System_IUserAuthenticationStatusChangingEventArgs<D>::CurrentStatus() const
    {
        llm::OS::System::UserAuthenticationStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserAuthenticationStatusChangingEventArgs)->get_CurrentStatus(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_System_IUserChangedEventArgs<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserChangedEventArgs)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::System::UserWatcherUpdateKind>) consume_Windows_System_IUserChangedEventArgs2<D>::ChangedPropertyKinds() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserChangedEventArgs2)->get_ChangedPropertyKinds(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::System::UserWatcherUpdateKind>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_IUserDeviceAssociationChangedEventArgs<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserDeviceAssociationChangedEventArgs)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_System_IUserDeviceAssociationChangedEventArgs<D>::NewUser() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserDeviceAssociationChangedEventArgs)->get_NewUser(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_System_IUserDeviceAssociationChangedEventArgs<D>::OldUser() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserDeviceAssociationChangedEventArgs)->get_OldUser(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_System_IUserDeviceAssociationStatics<D>::FindUserFromDeviceId(param::hstring const& deviceId) const
    {
        void* user{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserDeviceAssociationStatics)->FindUserFromDeviceId(*(void**)(&deviceId), &user));
        return llm::OS::System::User{ user, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_IUserDeviceAssociationStatics<D>::UserDeviceAssociationChanged(llm::OS::Foundation::EventHandler<llm::OS::System::UserDeviceAssociationChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserDeviceAssociationStatics)->add_UserDeviceAssociationChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_IUserDeviceAssociationStatics<D>::UserDeviceAssociationChanged_revoker consume_Windows_System_IUserDeviceAssociationStatics<D>::UserDeviceAssociationChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::System::UserDeviceAssociationChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, UserDeviceAssociationChanged_revoker>(this, UserDeviceAssociationChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IUserDeviceAssociationStatics<D>::UserDeviceAssociationChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::IUserDeviceAssociationStatics)->remove_UserDeviceAssociationChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_IUserPicker<D>::AllowGuestAccounts() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserPicker)->get_AllowGuestAccounts(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IUserPicker<D>::AllowGuestAccounts(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserPicker)->put_AllowGuestAccounts(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_System_IUserPicker<D>::SuggestedSelectedUser() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserPicker)->get_SuggestedSelectedUser(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IUserPicker<D>::SuggestedSelectedUser(llm::OS::System::User const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserPicker)->put_SuggestedSelectedUser(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::User>) consume_Windows_System_IUserPicker<D>::PickSingleUserAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserPicker)->PickSingleUserAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::User>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_IUserPickerStatics<D>::IsSupported() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserPickerStatics)->IsSupported(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::UserWatcher) consume_Windows_System_IUserStatics<D>::CreateWatcher() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserStatics)->CreateWatcher(&result));
        return llm::OS::System::UserWatcher{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::System::User>>) consume_Windows_System_IUserStatics<D>::FindAllAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserStatics)->FindAllAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::System::User>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::System::User>>) consume_Windows_System_IUserStatics<D>::FindAllAsync(llm::OS::System::UserType const& type) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserStatics)->FindAllAsyncByType(static_cast<int32_t>(type), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::System::User>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::System::User>>) consume_Windows_System_IUserStatics<D>::FindAllAsync(llm::OS::System::UserType const& type, llm::OS::System::UserAuthenticationStatus const& status) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserStatics)->FindAllAsyncByTypeAndStatus(static_cast<int32_t>(type), static_cast<int32_t>(status), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::System::User>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_System_IUserStatics<D>::GetFromId(param::hstring const& nonRoamableId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserStatics)->GetFromId(*(void**)(&nonRoamableId), &result));
        return llm::OS::System::User{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_System_IUserStatics2<D>::GetDefault() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserStatics2)->GetDefault(&result));
        return llm::OS::System::User{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::UserWatcherStatus) consume_Windows_System_IUserWatcher<D>::Status() const
    {
        llm::OS::System::UserWatcherStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserWatcher)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IUserWatcher<D>::Start() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserWatcher)->Start());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IUserWatcher<D>::Stop() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserWatcher)->Stop());
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_IUserWatcher<D>::Added(llm::OS::Foundation::TypedEventHandler<llm::OS::System::UserWatcher, llm::OS::System::UserChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserWatcher)->add_Added(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_IUserWatcher<D>::Added_revoker consume_Windows_System_IUserWatcher<D>::Added(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::UserWatcher, llm::OS::System::UserChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Added_revoker>(this, Added(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IUserWatcher<D>::Added(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::IUserWatcher)->remove_Added(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_IUserWatcher<D>::Removed(llm::OS::Foundation::TypedEventHandler<llm::OS::System::UserWatcher, llm::OS::System::UserChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserWatcher)->add_Removed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_IUserWatcher<D>::Removed_revoker consume_Windows_System_IUserWatcher<D>::Removed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::UserWatcher, llm::OS::System::UserChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Removed_revoker>(this, Removed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IUserWatcher<D>::Removed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::IUserWatcher)->remove_Removed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_IUserWatcher<D>::Updated(llm::OS::Foundation::TypedEventHandler<llm::OS::System::UserWatcher, llm::OS::System::UserChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserWatcher)->add_Updated(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_IUserWatcher<D>::Updated_revoker consume_Windows_System_IUserWatcher<D>::Updated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::UserWatcher, llm::OS::System::UserChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Updated_revoker>(this, Updated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IUserWatcher<D>::Updated(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::IUserWatcher)->remove_Updated(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_IUserWatcher<D>::AuthenticationStatusChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::System::UserWatcher, llm::OS::System::UserChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserWatcher)->add_AuthenticationStatusChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_IUserWatcher<D>::AuthenticationStatusChanged_revoker consume_Windows_System_IUserWatcher<D>::AuthenticationStatusChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::UserWatcher, llm::OS::System::UserChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, AuthenticationStatusChanged_revoker>(this, AuthenticationStatusChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IUserWatcher<D>::AuthenticationStatusChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::IUserWatcher)->remove_AuthenticationStatusChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_IUserWatcher<D>::AuthenticationStatusChanging(llm::OS::Foundation::TypedEventHandler<llm::OS::System::UserWatcher, llm::OS::System::UserAuthenticationStatusChangingEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserWatcher)->add_AuthenticationStatusChanging(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_IUserWatcher<D>::AuthenticationStatusChanging_revoker consume_Windows_System_IUserWatcher<D>::AuthenticationStatusChanging(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::UserWatcher, llm::OS::System::UserAuthenticationStatusChangingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, AuthenticationStatusChanging_revoker>(this, AuthenticationStatusChanging(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IUserWatcher<D>::AuthenticationStatusChanging(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::IUserWatcher)->remove_AuthenticationStatusChanging(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_IUserWatcher<D>::EnumerationCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::System::UserWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserWatcher)->add_EnumerationCompleted(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_IUserWatcher<D>::EnumerationCompleted_revoker consume_Windows_System_IUserWatcher<D>::EnumerationCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::UserWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, EnumerationCompleted_revoker>(this, EnumerationCompleted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IUserWatcher<D>::EnumerationCompleted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::IUserWatcher)->remove_EnumerationCompleted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_IUserWatcher<D>::Stopped(llm::OS::Foundation::TypedEventHandler<llm::OS::System::UserWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::IUserWatcher)->add_Stopped(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_IUserWatcher<D>::Stopped_revoker consume_Windows_System_IUserWatcher<D>::Stopped(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::UserWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, Stopped_revoker>(this, Stopped(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_IUserWatcher<D>::Stopped(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::IUserWatcher)->remove_Stopped(impl::bind_in(token));
    }
    template <typename H> struct delegate<llm::OS::System::DispatcherQueueHandler, H> final : implements_delegate<llm::OS::System::DispatcherQueueHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::System::DispatcherQueueHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke() noexcept final try
        {
            (*this)();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppActivationResult> : produce_base<D, llm::OS::System::IAppActivationResult>
    {
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AppResourceGroupInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::AppResourceGroupInfo>(this->shim().AppResourceGroupInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppDiagnosticInfo> : produce_base<D, llm::OS::System::IAppDiagnosticInfo>
    {
        int32_t __stdcall get_AppInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::AppInfo>(this->shim().AppInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppDiagnosticInfo2> : produce_base<D, llm::OS::System::IAppDiagnosticInfo2>
    {
        int32_t __stdcall GetResourceGroups(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::System::AppResourceGroupInfo>>(this->shim().GetResourceGroups());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateResourceGroupWatcher(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::AppResourceGroupInfoWatcher>(this->shim().CreateResourceGroupWatcher());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppDiagnosticInfo3> : produce_base<D, llm::OS::System::IAppDiagnosticInfo3>
    {
        int32_t __stdcall LaunchAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::AppActivationResult>>(this->shim().LaunchAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppDiagnosticInfoStatics> : produce_base<D, llm::OS::System::IAppDiagnosticInfoStatics>
    {
        int32_t __stdcall RequestInfoAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::System::AppDiagnosticInfo>>>(this->shim().RequestInfoAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppDiagnosticInfoStatics2> : produce_base<D, llm::OS::System::IAppDiagnosticInfoStatics2>
    {
        int32_t __stdcall CreateWatcher(void** watcher) noexcept final try
        {
            clear_abi(watcher);
            typename D::abi_guard guard(this->shim());
            *watcher = detach_from<llm::OS::System::AppDiagnosticInfoWatcher>(this->shim().CreateWatcher());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestAccessAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::DiagnosticAccessStatus>>(this->shim().RequestAccessAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestInfoForPackageAsync(void* packageFamilyName, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::System::AppDiagnosticInfo>>>(this->shim().RequestInfoForPackageAsync(*reinterpret_cast<hstring const*>(&packageFamilyName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestInfoForAppAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::System::AppDiagnosticInfo>>>(this->shim().RequestInfoForAppAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestInfoForAppUserModelId(void* appUserModelId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::System::AppDiagnosticInfo>>>(this->shim().RequestInfoForAppAsync(*reinterpret_cast<hstring const*>(&appUserModelId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppDiagnosticInfoWatcher> : produce_base<D, llm::OS::System::IAppDiagnosticInfoWatcher>
    {
        int32_t __stdcall add_Added(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Added(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppDiagnosticInfoWatcher, llm::OS::System::AppDiagnosticInfoWatcherEventArgs> const*>(&handler)));
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
            *token = detach_from<llm::event_token>(this->shim().Removed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppDiagnosticInfoWatcher, llm::OS::System::AppDiagnosticInfoWatcherEventArgs> const*>(&handler)));
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
            *token = detach_from<llm::event_token>(this->shim().EnumerationCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppDiagnosticInfoWatcher, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_EnumerationCompleted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnumerationCompleted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Stopped(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Stopped(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppDiagnosticInfoWatcher, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Stopped(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stopped(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::AppDiagnosticInfoWatcherStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
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
    struct produce<D, llm::OS::System::IAppDiagnosticInfoWatcherEventArgs> : produce_base<D, llm::OS::System::IAppDiagnosticInfoWatcherEventArgs>
    {
        int32_t __stdcall get_AppDiagnosticInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::AppDiagnosticInfo>(this->shim().AppDiagnosticInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppExecutionStateChangeResult> : produce_base<D, llm::OS::System::IAppExecutionStateChangeResult>
    {
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppMemoryReport> : produce_base<D, llm::OS::System::IAppMemoryReport>
    {
        int32_t __stdcall get_PrivateCommitUsage(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().PrivateCommitUsage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PeakPrivateCommitUsage(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().PeakPrivateCommitUsage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TotalCommitUsage(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().TotalCommitUsage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TotalCommitLimit(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().TotalCommitLimit());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppMemoryReport2> : produce_base<D, llm::OS::System::IAppMemoryReport2>
    {
        int32_t __stdcall get_ExpectedTotalCommitLimit(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().ExpectedTotalCommitLimit());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppMemoryUsageLimitChangingEventArgs> : produce_base<D, llm::OS::System::IAppMemoryUsageLimitChangingEventArgs>
    {
        int32_t __stdcall get_OldLimit(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().OldLimit());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NewLimit(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().NewLimit());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppResourceGroupBackgroundTaskReport> : produce_base<D, llm::OS::System::IAppResourceGroupBackgroundTaskReport>
    {
        int32_t __stdcall get_TaskId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().TaskId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Trigger(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Trigger());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EntryPoint(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().EntryPoint());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppResourceGroupInfo> : produce_base<D, llm::OS::System::IAppResourceGroupInfo>
    {
        int32_t __stdcall get_InstanceId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().InstanceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsShared(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsShared());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetBackgroundTaskReports(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::System::AppResourceGroupBackgroundTaskReport>>(this->shim().GetBackgroundTaskReports());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetMemoryReport(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::AppResourceGroupMemoryReport>(this->shim().GetMemoryReport());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetProcessDiagnosticInfos(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::System::Diagnostics::ProcessDiagnosticInfo>>(this->shim().GetProcessDiagnosticInfos());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetStateReport(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::AppResourceGroupStateReport>(this->shim().GetStateReport());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppResourceGroupInfo2> : produce_base<D, llm::OS::System::IAppResourceGroupInfo2>
    {
        int32_t __stdcall StartSuspendAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::AppExecutionStateChangeResult>>(this->shim().StartSuspendAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartResumeAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::AppExecutionStateChangeResult>>(this->shim().StartResumeAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartTerminateAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::AppExecutionStateChangeResult>>(this->shim().StartTerminateAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppResourceGroupInfoWatcher> : produce_base<D, llm::OS::System::IAppResourceGroupInfoWatcher>
    {
        int32_t __stdcall add_Added(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Added(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppResourceGroupInfoWatcher, llm::OS::System::AppResourceGroupInfoWatcherEventArgs> const*>(&handler)));
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
            *token = detach_from<llm::event_token>(this->shim().Removed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppResourceGroupInfoWatcher, llm::OS::System::AppResourceGroupInfoWatcherEventArgs> const*>(&handler)));
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
            *token = detach_from<llm::event_token>(this->shim().EnumerationCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppResourceGroupInfoWatcher, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_EnumerationCompleted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnumerationCompleted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Stopped(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Stopped(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppResourceGroupInfoWatcher, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Stopped(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stopped(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_ExecutionStateChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ExecutionStateChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::AppResourceGroupInfoWatcher, llm::OS::System::AppResourceGroupInfoWatcherExecutionStateChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ExecutionStateChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExecutionStateChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_Status(int32_t* status) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_from<llm::OS::System::AppResourceGroupInfoWatcherStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
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
    struct produce<D, llm::OS::System::IAppResourceGroupInfoWatcherEventArgs> : produce_base<D, llm::OS::System::IAppResourceGroupInfoWatcherEventArgs>
    {
        int32_t __stdcall get_AppDiagnosticInfos(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::System::AppDiagnosticInfo>>(this->shim().AppDiagnosticInfos());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AppResourceGroupInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::AppResourceGroupInfo>(this->shim().AppResourceGroupInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppResourceGroupInfoWatcherExecutionStateChangedEventArgs> : produce_base<D, llm::OS::System::IAppResourceGroupInfoWatcherExecutionStateChangedEventArgs>
    {
        int32_t __stdcall get_AppDiagnosticInfos(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::System::AppDiagnosticInfo>>(this->shim().AppDiagnosticInfos());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AppResourceGroupInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::AppResourceGroupInfo>(this->shim().AppResourceGroupInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppResourceGroupMemoryReport> : produce_base<D, llm::OS::System::IAppResourceGroupMemoryReport>
    {
        int32_t __stdcall get_CommitUsageLimit(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().CommitUsageLimit());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CommitUsageLevel(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::AppMemoryUsageLevel>(this->shim().CommitUsageLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PrivateCommitUsage(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().PrivateCommitUsage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TotalCommitUsage(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().TotalCommitUsage());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppResourceGroupStateReport> : produce_base<D, llm::OS::System::IAppResourceGroupStateReport>
    {
        int32_t __stdcall get_ExecutionState(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::AppResourceGroupExecutionState>(this->shim().ExecutionState());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EnergyQuotaState(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::AppResourceGroupEnergyQuotaState>(this->shim().EnergyQuotaState());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppUriHandlerHost> : produce_base<D, llm::OS::System::IAppUriHandlerHost>
    {
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Name(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppUriHandlerHost2> : produce_base<D, llm::OS::System::IAppUriHandlerHost2>
    {
        int32_t __stdcall get_IsEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppUriHandlerHostFactory> : produce_base<D, llm::OS::System::IAppUriHandlerHostFactory>
    {
        int32_t __stdcall CreateInstance(void* name, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::AppUriHandlerHost>(this->shim().CreateInstance(*reinterpret_cast<hstring const*>(&name)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppUriHandlerRegistration> : produce_base<D, llm::OS::System::IAppUriHandlerRegistration>
    {
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAppAddedHostsAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::System::AppUriHandlerHost>>>(this->shim().GetAppAddedHostsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetAppAddedHostsAsync(void* hosts, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SetAppAddedHostsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::System::AppUriHandlerHost> const*>(&hosts)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppUriHandlerRegistration2> : produce_base<D, llm::OS::System::IAppUriHandlerRegistration2>
    {
        int32_t __stdcall GetAllHosts(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::System::AppUriHandlerHost>>(this->shim().GetAllHosts());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UpdateHosts(void* hosts) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateHosts(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::System::AppUriHandlerHost> const*>(&hosts));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PackageFamilyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PackageFamilyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppUriHandlerRegistrationManager> : produce_base<D, llm::OS::System::IAppUriHandlerRegistrationManager>
    {
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetRegistration(void* name, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::AppUriHandlerRegistration>(this->shim().TryGetRegistration(*reinterpret_cast<hstring const*>(&name)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppUriHandlerRegistrationManager2> : produce_base<D, llm::OS::System::IAppUriHandlerRegistrationManager2>
    {
        int32_t __stdcall get_PackageFamilyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PackageFamilyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppUriHandlerRegistrationManagerStatics> : produce_base<D, llm::OS::System::IAppUriHandlerRegistrationManagerStatics>
    {
        int32_t __stdcall GetDefault(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::AppUriHandlerRegistrationManager>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetForUser(void* user, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::AppUriHandlerRegistrationManager>(this->shim().GetForUser(*reinterpret_cast<llm::OS::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IAppUriHandlerRegistrationManagerStatics2> : produce_base<D, llm::OS::System::IAppUriHandlerRegistrationManagerStatics2>
    {
        int32_t __stdcall GetForPackage(void* packageFamilyName, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::AppUriHandlerRegistrationManager>(this->shim().GetForPackage(*reinterpret_cast<hstring const*>(&packageFamilyName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetForPackageForUser(void* packageFamilyName, void* user, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::AppUriHandlerRegistrationManager>(this->shim().GetForPackageForUser(*reinterpret_cast<hstring const*>(&packageFamilyName), *reinterpret_cast<llm::OS::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IDateTimeSettingsStatics> : produce_base<D, llm::OS::System::IDateTimeSettingsStatics>
    {
        int32_t __stdcall SetSystemDateTime(int64_t utcDateTime) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetSystemDateTime(*reinterpret_cast<llm::OS::Foundation::DateTime const*>(&utcDateTime));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IDispatcherQueue> : produce_base<D, llm::OS::System::IDispatcherQueue>
    {
        int32_t __stdcall CreateTimer(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::DispatcherQueueTimer>(this->shim().CreateTimer());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryEnqueue(void* callback, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().TryEnqueue(*reinterpret_cast<llm::OS::System::DispatcherQueueHandler const*>(&callback)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryEnqueueWithPriority(int32_t priority, void* callback, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().TryEnqueue(*reinterpret_cast<llm::OS::System::DispatcherQueuePriority const*>(&priority), *reinterpret_cast<llm::OS::System::DispatcherQueueHandler const*>(&callback)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_ShutdownStarting(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ShutdownStarting(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::DispatcherQueue, llm::OS::System::DispatcherQueueShutdownStartingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ShutdownStarting(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShutdownStarting(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_ShutdownCompleted(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ShutdownCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::DispatcherQueue, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ShutdownCompleted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShutdownCompleted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IDispatcherQueue2> : produce_base<D, llm::OS::System::IDispatcherQueue2>
    {
        int32_t __stdcall get_HasThreadAccess(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().HasThreadAccess());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IDispatcherQueueController> : produce_base<D, llm::OS::System::IDispatcherQueueController>
    {
        int32_t __stdcall get_DispatcherQueue(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::DispatcherQueue>(this->shim().DispatcherQueue());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShutdownQueueAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ShutdownQueueAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IDispatcherQueueControllerStatics> : produce_base<D, llm::OS::System::IDispatcherQueueControllerStatics>
    {
        int32_t __stdcall CreateOnDedicatedThread(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::DispatcherQueueController>(this->shim().CreateOnDedicatedThread());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IDispatcherQueueShutdownStartingEventArgs> : produce_base<D, llm::OS::System::IDispatcherQueueShutdownStartingEventArgs>
    {
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
    struct produce<D, llm::OS::System::IDispatcherQueueStatics> : produce_base<D, llm::OS::System::IDispatcherQueueStatics>
    {
        int32_t __stdcall GetForCurrentThread(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::DispatcherQueue>(this->shim().GetForCurrentThread());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IDispatcherQueueTimer> : produce_base<D, llm::OS::System::IDispatcherQueueTimer>
    {
        int32_t __stdcall get_Interval(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Interval());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Interval(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Interval(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsRunning(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsRunning());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsRepeating(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsRepeating());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsRepeating(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsRepeating(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
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
        int32_t __stdcall add_Tick(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Tick(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::DispatcherQueueTimer, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Tick(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Tick(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IFolderLauncherOptions> : produce_base<D, llm::OS::System::IFolderLauncherOptions>
    {
        int32_t __stdcall get_ItemsToSelect(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Storage::IStorageItem>>(this->shim().ItemsToSelect());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IKnownUserPropertiesStatics> : produce_base<D, llm::OS::System::IKnownUserPropertiesStatics>
    {
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FirstName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().FirstName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LastName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().LastName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProviderName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ProviderName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AccountName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AccountName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_GuestHost(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GuestHost());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PrincipalName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PrincipalName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DomainName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DomainName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SessionInitiationProtocolUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SessionInitiationProtocolUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IKnownUserPropertiesStatics2> : produce_base<D, llm::OS::System::IKnownUserPropertiesStatics2>
    {
        int32_t __stdcall get_AgeEnforcementRegion(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AgeEnforcementRegion());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::ILaunchUriResult> : produce_base<D, llm::OS::System::ILaunchUriResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::LaunchUriStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Result(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::ValueSet>(this->shim().Result());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::ILauncherOptions> : produce_base<D, llm::OS::System::ILauncherOptions>
    {
        int32_t __stdcall get_TreatAsUntrusted(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().TreatAsUntrusted());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TreatAsUntrusted(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TreatAsUntrusted(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayApplicationPicker(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().DisplayApplicationPicker());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DisplayApplicationPicker(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayApplicationPicker(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UI(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::LauncherUIOptions>(this->shim().UI());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PreferredApplicationPackageFamilyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PreferredApplicationPackageFamilyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PreferredApplicationPackageFamilyName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PreferredApplicationPackageFamilyName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PreferredApplicationDisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PreferredApplicationDisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PreferredApplicationDisplayName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PreferredApplicationDisplayName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FallbackUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().FallbackUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_FallbackUri(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FallbackUri(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ContentType(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ContentType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ContentType(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentType(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::ILauncherOptions2> : produce_base<D, llm::OS::System::ILauncherOptions2>
    {
        int32_t __stdcall get_TargetApplicationPackageFamilyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().TargetApplicationPackageFamilyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TargetApplicationPackageFamilyName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetApplicationPackageFamilyName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NeighboringFilesQuery(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Search::StorageFileQueryResult>(this->shim().NeighboringFilesQuery());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_NeighboringFilesQuery(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NeighboringFilesQuery(*reinterpret_cast<llm::OS::Storage::Search::StorageFileQueryResult const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::ILauncherOptions3> : produce_base<D, llm::OS::System::ILauncherOptions3>
    {
        int32_t __stdcall get_IgnoreAppUriHandlers(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IgnoreAppUriHandlers());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IgnoreAppUriHandlers(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IgnoreAppUriHandlers(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::ILauncherOptions4> : produce_base<D, llm::OS::System::ILauncherOptions4>
    {
        int32_t __stdcall get_LimitPickerToCurrentAppAndAppUriHandlers(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().LimitPickerToCurrentAppAndAppUriHandlers());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_LimitPickerToCurrentAppAndAppUriHandlers(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LimitPickerToCurrentAppAndAppUriHandlers(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::ILauncherStatics> : produce_base<D, llm::OS::System::ILauncherStatics>
    {
        int32_t __stdcall LaunchFileAsync(void* file, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().LaunchFileAsync(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&file)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchFileWithOptionsAsync(void* file, void* options, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().LaunchFileAsync(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&file), *reinterpret_cast<llm::OS::System::LauncherOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchUriAsync(void* uri, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().LaunchUriAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchUriWithOptionsAsync(void* uri, void* options, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().LaunchUriAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::System::LauncherOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::ILauncherStatics2> : produce_base<D, llm::OS::System::ILauncherStatics2>
    {
        int32_t __stdcall LaunchUriForResultsAsync(void* uri, void* options, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchUriResult>>(this->shim().LaunchUriForResultsAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::System::LauncherOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchUriForResultsWithDataAsync(void* uri, void* options, void* inputData, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchUriResult>>(this->shim().LaunchUriForResultsAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::System::LauncherOptions const*>(&options), *reinterpret_cast<llm::OS::Foundation::Collections::ValueSet const*>(&inputData)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchUriWithDataAsync(void* uri, void* options, void* inputData, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().LaunchUriAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::System::LauncherOptions const*>(&options), *reinterpret_cast<llm::OS::Foundation::Collections::ValueSet const*>(&inputData)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall QueryUriSupportAsync(void* uri, int32_t launchQuerySupportType, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchQuerySupportStatus>>(this->shim().QueryUriSupportAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::System::LaunchQuerySupportType const*>(&launchQuerySupportType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall QueryUriSupportWithPackageFamilyNameAsync(void* uri, int32_t launchQuerySupportType, void* packageFamilyName, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchQuerySupportStatus>>(this->shim().QueryUriSupportAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::System::LaunchQuerySupportType const*>(&launchQuerySupportType), *reinterpret_cast<hstring const*>(&packageFamilyName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall QueryFileSupportAsync(void* file, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchQuerySupportStatus>>(this->shim().QueryFileSupportAsync(*reinterpret_cast<llm::OS::Storage::StorageFile const*>(&file)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall QueryFileSupportWithPackageFamilyNameAsync(void* file, void* packageFamilyName, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchQuerySupportStatus>>(this->shim().QueryFileSupportAsync(*reinterpret_cast<llm::OS::Storage::StorageFile const*>(&file), *reinterpret_cast<hstring const*>(&packageFamilyName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindUriSchemeHandlersAsync(void* scheme, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppInfo>>>(this->shim().FindUriSchemeHandlersAsync(*reinterpret_cast<hstring const*>(&scheme)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindUriSchemeHandlersWithLaunchUriTypeAsync(void* scheme, int32_t launchQuerySupportType, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppInfo>>>(this->shim().FindUriSchemeHandlersAsync(*reinterpret_cast<hstring const*>(&scheme), *reinterpret_cast<llm::OS::System::LaunchQuerySupportType const*>(&launchQuerySupportType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindFileHandlersAsync(void* extension, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppInfo>>>(this->shim().FindFileHandlersAsync(*reinterpret_cast<hstring const*>(&extension)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::ILauncherStatics3> : produce_base<D, llm::OS::System::ILauncherStatics3>
    {
        int32_t __stdcall LaunchFolderAsync(void* folder, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().LaunchFolderAsync(*reinterpret_cast<llm::OS::Storage::IStorageFolder const*>(&folder)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchFolderWithOptionsAsync(void* folder, void* options, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().LaunchFolderAsync(*reinterpret_cast<llm::OS::Storage::IStorageFolder const*>(&folder), *reinterpret_cast<llm::OS::System::FolderLauncherOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::ILauncherStatics4> : produce_base<D, llm::OS::System::ILauncherStatics4>
    {
        int32_t __stdcall QueryAppUriSupportAsync(void* uri, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchQuerySupportStatus>>(this->shim().QueryAppUriSupportAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall QueryAppUriSupportWithPackageFamilyNameAsync(void* uri, void* packageFamilyName, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchQuerySupportStatus>>(this->shim().QueryAppUriSupportAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<hstring const*>(&packageFamilyName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindAppUriHandlersAsync(void* uri, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppInfo>>>(this->shim().FindAppUriHandlersAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchUriForUserAsync(void* user, void* uri, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchUriStatus>>(this->shim().LaunchUriForUserAsync(*reinterpret_cast<llm::OS::System::User const*>(&user), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchUriWithOptionsForUserAsync(void* user, void* uri, void* options, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchUriStatus>>(this->shim().LaunchUriForUserAsync(*reinterpret_cast<llm::OS::System::User const*>(&user), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::System::LauncherOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchUriWithDataForUserAsync(void* user, void* uri, void* options, void* inputData, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchUriStatus>>(this->shim().LaunchUriForUserAsync(*reinterpret_cast<llm::OS::System::User const*>(&user), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::System::LauncherOptions const*>(&options), *reinterpret_cast<llm::OS::Foundation::Collections::ValueSet const*>(&inputData)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchUriForResultsForUserAsync(void* user, void* uri, void* options, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchUriResult>>(this->shim().LaunchUriForResultsForUserAsync(*reinterpret_cast<llm::OS::System::User const*>(&user), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::System::LauncherOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchUriForResultsWithDataForUserAsync(void* user, void* uri, void* options, void* inputData, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::LaunchUriResult>>(this->shim().LaunchUriForResultsForUserAsync(*reinterpret_cast<llm::OS::System::User const*>(&user), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::System::LauncherOptions const*>(&options), *reinterpret_cast<llm::OS::Foundation::Collections::ValueSet const*>(&inputData)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::ILauncherStatics5> : produce_base<D, llm::OS::System::ILauncherStatics5>
    {
        int32_t __stdcall LaunchFolderPathAsync(void* path, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().LaunchFolderPathAsync(*reinterpret_cast<hstring const*>(&path)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchFolderPathWithOptionsAsync(void* path, void* options, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().LaunchFolderPathAsync(*reinterpret_cast<hstring const*>(&path), *reinterpret_cast<llm::OS::System::FolderLauncherOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchFolderPathForUserAsync(void* user, void* path, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().LaunchFolderPathForUserAsync(*reinterpret_cast<llm::OS::System::User const*>(&user), *reinterpret_cast<hstring const*>(&path)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchFolderPathWithOptionsForUserAsync(void* user, void* path, void* options, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().LaunchFolderPathForUserAsync(*reinterpret_cast<llm::OS::System::User const*>(&user), *reinterpret_cast<hstring const*>(&path), *reinterpret_cast<llm::OS::System::FolderLauncherOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::ILauncherUIOptions> : produce_base<D, llm::OS::System::ILauncherUIOptions>
    {
        int32_t __stdcall get_InvocationPoint(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::Point>>(this->shim().InvocationPoint());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InvocationPoint(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InvocationPoint(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::Foundation::Point> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SelectionRect(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::Rect>>(this->shim().SelectionRect());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SelectionRect(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectionRect(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::Foundation::Rect> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PreferredPlacement(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Popups::Placement>(this->shim().PreferredPlacement());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PreferredPlacement(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PreferredPlacement(*reinterpret_cast<llm::OS::UI::Popups::Placement const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::System::ILauncherViewOptions> : produce_base<D, llm::OS::System::ILauncherViewOptions>
    {
        int32_t __stdcall get_DesiredRemainingView(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::ViewManagement::ViewSizePreference>(this->shim().DesiredRemainingView());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DesiredRemainingView(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredRemainingView(*reinterpret_cast<llm::OS::UI::ViewManagement::ViewSizePreference const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IMemoryManagerStatics> : produce_base<D, llm::OS::System::IMemoryManagerStatics>
    {
        int32_t __stdcall get_AppMemoryUsage(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().AppMemoryUsage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AppMemoryUsageLimit(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().AppMemoryUsageLimit());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AppMemoryUsageLevel(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::AppMemoryUsageLevel>(this->shim().AppMemoryUsageLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_AppMemoryUsageIncreased(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AppMemoryUsageIncreased(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AppMemoryUsageIncreased(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppMemoryUsageIncreased(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_AppMemoryUsageDecreased(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AppMemoryUsageDecreased(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AppMemoryUsageDecreased(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppMemoryUsageDecreased(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_AppMemoryUsageLimitChanging(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AppMemoryUsageLimitChanging(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::System::AppMemoryUsageLimitChangingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AppMemoryUsageLimitChanging(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppMemoryUsageLimitChanging(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IMemoryManagerStatics2> : produce_base<D, llm::OS::System::IMemoryManagerStatics2>
    {
        int32_t __stdcall GetAppMemoryReport(void** memoryReport) noexcept final try
        {
            clear_abi(memoryReport);
            typename D::abi_guard guard(this->shim());
            *memoryReport = detach_from<llm::OS::System::AppMemoryReport>(this->shim().GetAppMemoryReport());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetProcessMemoryReport(void** memoryReport) noexcept final try
        {
            clear_abi(memoryReport);
            typename D::abi_guard guard(this->shim());
            *memoryReport = detach_from<llm::OS::System::ProcessMemoryReport>(this->shim().GetProcessMemoryReport());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IMemoryManagerStatics3> : produce_base<D, llm::OS::System::IMemoryManagerStatics3>
    {
        int32_t __stdcall TrySetAppMemoryUsageLimit(uint64_t value, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().TrySetAppMemoryUsageLimit(value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IMemoryManagerStatics4> : produce_base<D, llm::OS::System::IMemoryManagerStatics4>
    {
        int32_t __stdcall get_ExpectedAppMemoryUsageLimit(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().ExpectedAppMemoryUsageLimit());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IProcessLauncherOptions> : produce_base<D, llm::OS::System::IProcessLauncherOptions>
    {
        int32_t __stdcall get_StandardInput(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IInputStream>(this->shim().StandardInput());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_StandardInput(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StandardInput(*reinterpret_cast<llm::OS::Storage::Streams::IInputStream const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StandardOutput(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IOutputStream>(this->shim().StandardOutput());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_StandardOutput(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StandardOutput(*reinterpret_cast<llm::OS::Storage::Streams::IOutputStream const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StandardError(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IOutputStream>(this->shim().StandardError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_StandardError(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StandardError(*reinterpret_cast<llm::OS::Storage::Streams::IOutputStream const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WorkingDirectory(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().WorkingDirectory());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_WorkingDirectory(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WorkingDirectory(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IProcessLauncherResult> : produce_base<D, llm::OS::System::IProcessLauncherResult>
    {
        int32_t __stdcall get_ExitCode(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ExitCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IProcessLauncherStatics> : produce_base<D, llm::OS::System::IProcessLauncherStatics>
    {
        int32_t __stdcall RunToCompletionAsync(void* fileName, void* args, void** asyncOperationResult) noexcept final try
        {
            clear_abi(asyncOperationResult);
            typename D::abi_guard guard(this->shim());
            *asyncOperationResult = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::ProcessLauncherResult>>(this->shim().RunToCompletionAsync(*reinterpret_cast<hstring const*>(&fileName), *reinterpret_cast<hstring const*>(&args)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RunToCompletionAsyncWithOptions(void* fileName, void* args, void* options, void** asyncOperationResult) noexcept final try
        {
            clear_abi(asyncOperationResult);
            typename D::abi_guard guard(this->shim());
            *asyncOperationResult = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::ProcessLauncherResult>>(this->shim().RunToCompletionAsync(*reinterpret_cast<hstring const*>(&fileName), *reinterpret_cast<hstring const*>(&args), *reinterpret_cast<llm::OS::System::ProcessLauncherOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IProcessMemoryReport> : produce_base<D, llm::OS::System::IProcessMemoryReport>
    {
        int32_t __stdcall get_PrivateWorkingSetUsage(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().PrivateWorkingSetUsage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TotalWorkingSetUsage(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().TotalWorkingSetUsage());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IProtocolForResultsOperation> : produce_base<D, llm::OS::System::IProtocolForResultsOperation>
    {
        int32_t __stdcall ReportCompleted(void* data) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCompleted(*reinterpret_cast<llm::OS::Foundation::Collections::ValueSet const*>(&data));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IRemoteLauncherOptions> : produce_base<D, llm::OS::System::IRemoteLauncherOptions>
    {
        int32_t __stdcall get_FallbackUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().FallbackUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_FallbackUri(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FallbackUri(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PreferredAppIds(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().PreferredAppIds());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IRemoteLauncherStatics> : produce_base<D, llm::OS::System::IRemoteLauncherStatics>
    {
        int32_t __stdcall LaunchUriAsync(void* remoteSystemConnectionRequest, void* uri, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::RemoteLaunchUriStatus>>(this->shim().LaunchUriAsync(*reinterpret_cast<llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest const*>(&remoteSystemConnectionRequest), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchUriWithOptionsAsync(void* remoteSystemConnectionRequest, void* uri, void* options, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::RemoteLaunchUriStatus>>(this->shim().LaunchUriAsync(*reinterpret_cast<llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest const*>(&remoteSystemConnectionRequest), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::System::RemoteLauncherOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchUriWithDataAsync(void* remoteSystemConnectionRequest, void* uri, void* options, void* inputData, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::RemoteLaunchUriStatus>>(this->shim().LaunchUriAsync(*reinterpret_cast<llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest const*>(&remoteSystemConnectionRequest), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::System::RemoteLauncherOptions const*>(&options), *reinterpret_cast<llm::OS::Foundation::Collections::ValueSet const*>(&inputData)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IShutdownManagerStatics> : produce_base<D, llm::OS::System::IShutdownManagerStatics>
    {
        int32_t __stdcall BeginShutdown(int32_t shutdownKind, int64_t timeout) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BeginShutdown(*reinterpret_cast<llm::OS::System::ShutdownKind const*>(&shutdownKind), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&timeout));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CancelShutdown() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CancelShutdown();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IShutdownManagerStatics2> : produce_base<D, llm::OS::System::IShutdownManagerStatics2>
    {
        int32_t __stdcall IsPowerStateSupported(int32_t powerState, bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsPowerStateSupported(*reinterpret_cast<llm::OS::System::PowerState const*>(&powerState)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall EnterPowerState(int32_t powerState) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnterPowerState(*reinterpret_cast<llm::OS::System::PowerState const*>(&powerState));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall EnterPowerStateWithTimeSpan(int32_t powerState, int64_t wakeUpAfter) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnterPowerState(*reinterpret_cast<llm::OS::System::PowerState const*>(&powerState), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&wakeUpAfter));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::ITimeZoneSettingsStatics> : produce_base<D, llm::OS::System::ITimeZoneSettingsStatics>
    {
        int32_t __stdcall get_CurrentTimeZoneDisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CurrentTimeZoneDisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedTimeZoneDisplayNames(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().SupportedTimeZoneDisplayNames());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CanChangeTimeZone(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanChangeTimeZone());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ChangeTimeZoneByDisplayName(void* timeZoneDisplayName) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ChangeTimeZoneByDisplayName(*reinterpret_cast<hstring const*>(&timeZoneDisplayName));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::ITimeZoneSettingsStatics2> : produce_base<D, llm::OS::System::ITimeZoneSettingsStatics2>
    {
        int32_t __stdcall AutoUpdateTimeZoneAsync(int64_t timeout, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::AutoUpdateTimeZoneStatus>>(this->shim().AutoUpdateTimeZoneAsync(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&timeout)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IUser> : produce_base<D, llm::OS::System::IUser>
    {
        int32_t __stdcall get_NonRoamableId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().NonRoamableId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AuthenticationStatus(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::UserAuthenticationStatus>(this->shim().AuthenticationStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Type(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::UserType>(this->shim().Type());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPropertyAsync(void* value, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::IInspectable>>(this->shim().GetPropertyAsync(*reinterpret_cast<hstring const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPropertiesAsync(void* values, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IPropertySet>>(this->shim().GetPropertiesAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IVectorView<hstring> const*>(&values)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPictureAsync(int32_t desiredSize, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IRandomAccessStreamReference>>(this->shim().GetPictureAsync(*reinterpret_cast<llm::OS::System::UserPictureSize const*>(&desiredSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IUser2> : produce_base<D, llm::OS::System::IUser2>
    {
        int32_t __stdcall CheckUserAgeConsentGroupAsync(int32_t consentGroup, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::UserAgeConsentResult>>(this->shim().CheckUserAgeConsentGroupAsync(*reinterpret_cast<llm::OS::System::UserAgeConsentGroup const*>(&consentGroup)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IUserAuthenticationStatusChangeDeferral> : produce_base<D, llm::OS::System::IUserAuthenticationStatusChangeDeferral>
    {
        int32_t __stdcall Complete() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IUserAuthenticationStatusChangingEventArgs> : produce_base<D, llm::OS::System::IUserAuthenticationStatusChangingEventArgs>
    {
        int32_t __stdcall GetDeferral(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::UserAuthenticationStatusChangeDeferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NewStatus(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::UserAuthenticationStatus>(this->shim().NewStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CurrentStatus(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::UserAuthenticationStatus>(this->shim().CurrentStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IUserChangedEventArgs> : produce_base<D, llm::OS::System::IUserChangedEventArgs>
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
    struct produce<D, llm::OS::System::IUserChangedEventArgs2> : produce_base<D, llm::OS::System::IUserChangedEventArgs2>
    {
        int32_t __stdcall get_ChangedPropertyKinds(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::System::UserWatcherUpdateKind>>(this->shim().ChangedPropertyKinds());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IUserDeviceAssociationChangedEventArgs> : produce_base<D, llm::OS::System::IUserDeviceAssociationChangedEventArgs>
    {
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NewUser(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().NewUser());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OldUser(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().OldUser());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IUserDeviceAssociationStatics> : produce_base<D, llm::OS::System::IUserDeviceAssociationStatics>
    {
        int32_t __stdcall FindUserFromDeviceId(void* deviceId, void** user) noexcept final try
        {
            clear_abi(user);
            typename D::abi_guard guard(this->shim());
            *user = detach_from<llm::OS::System::User>(this->shim().FindUserFromDeviceId(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_UserDeviceAssociationChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().UserDeviceAssociationChanged(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::System::UserDeviceAssociationChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_UserDeviceAssociationChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UserDeviceAssociationChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IUserPicker> : produce_base<D, llm::OS::System::IUserPicker>
    {
        int32_t __stdcall get_AllowGuestAccounts(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AllowGuestAccounts());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AllowGuestAccounts(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowGuestAccounts(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SuggestedSelectedUser(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().SuggestedSelectedUser());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SuggestedSelectedUser(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuggestedSelectedUser(*reinterpret_cast<llm::OS::System::User const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PickSingleUserAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::User>>(this->shim().PickSingleUserAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IUserPickerStatics> : produce_base<D, llm::OS::System::IUserPickerStatics>
    {
        int32_t __stdcall IsSupported(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IUserStatics> : produce_base<D, llm::OS::System::IUserStatics>
    {
        int32_t __stdcall CreateWatcher(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::UserWatcher>(this->shim().CreateWatcher());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindAllAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::System::User>>>(this->shim().FindAllAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindAllAsyncByType(int32_t type, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::System::User>>>(this->shim().FindAllAsync(*reinterpret_cast<llm::OS::System::UserType const*>(&type)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindAllAsyncByTypeAndStatus(int32_t type, int32_t status, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::System::User>>>(this->shim().FindAllAsync(*reinterpret_cast<llm::OS::System::UserType const*>(&type), *reinterpret_cast<llm::OS::System::UserAuthenticationStatus const*>(&status)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFromId(void* nonRoamableId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::User>(this->shim().GetFromId(*reinterpret_cast<hstring const*>(&nonRoamableId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IUserStatics2> : produce_base<D, llm::OS::System::IUserStatics2>
    {
        int32_t __stdcall GetDefault(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::User>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::IUserWatcher> : produce_base<D, llm::OS::System::IUserWatcher>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::UserWatcherStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
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
        int32_t __stdcall add_Added(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Added(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::UserWatcher, llm::OS::System::UserChangedEventArgs> const*>(&handler)));
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
            *token = detach_from<llm::event_token>(this->shim().Removed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::UserWatcher, llm::OS::System::UserChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Removed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Removed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Updated(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Updated(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::UserWatcher, llm::OS::System::UserChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Updated(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Updated(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_AuthenticationStatusChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AuthenticationStatusChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::UserWatcher, llm::OS::System::UserChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AuthenticationStatusChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AuthenticationStatusChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_AuthenticationStatusChanging(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AuthenticationStatusChanging(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::UserWatcher, llm::OS::System::UserAuthenticationStatusChangingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AuthenticationStatusChanging(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AuthenticationStatusChanging(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_EnumerationCompleted(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().EnumerationCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::UserWatcher, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_EnumerationCompleted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnumerationCompleted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Stopped(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Stopped(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::UserWatcher, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Stopped(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stopped(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
}
LLM_EXPORT namespace llm::OS::System
{
    constexpr auto operator|(VirtualKeyModifiers const left, VirtualKeyModifiers const right) noexcept
    {
        return static_cast<VirtualKeyModifiers>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(VirtualKeyModifiers& left, VirtualKeyModifiers const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(VirtualKeyModifiers const left, VirtualKeyModifiers const right) noexcept
    {
        return static_cast<VirtualKeyModifiers>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(VirtualKeyModifiers& left, VirtualKeyModifiers const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(VirtualKeyModifiers const value) noexcept
    {
        return static_cast<VirtualKeyModifiers>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(VirtualKeyModifiers const left, VirtualKeyModifiers const right) noexcept
    {
        return static_cast<VirtualKeyModifiers>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(VirtualKeyModifiers& left, VirtualKeyModifiers const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto AppDiagnosticInfo::RequestInfoAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::System::AppDiagnosticInfo>>(*)(IAppDiagnosticInfoStatics const&), AppDiagnosticInfo, IAppDiagnosticInfoStatics>([](IAppDiagnosticInfoStatics const& f) { return f.RequestInfoAsync(); });
    }
    inline auto AppDiagnosticInfo::CreateWatcher()
    {
        return impl::call_factory_cast<llm::OS::System::AppDiagnosticInfoWatcher(*)(IAppDiagnosticInfoStatics2 const&), AppDiagnosticInfo, IAppDiagnosticInfoStatics2>([](IAppDiagnosticInfoStatics2 const& f) { return f.CreateWatcher(); });
    }
    inline auto AppDiagnosticInfo::RequestAccessAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::System::DiagnosticAccessStatus>(*)(IAppDiagnosticInfoStatics2 const&), AppDiagnosticInfo, IAppDiagnosticInfoStatics2>([](IAppDiagnosticInfoStatics2 const& f) { return f.RequestAccessAsync(); });
    }
    inline auto AppDiagnosticInfo::RequestInfoForPackageAsync(param::hstring const& packageFamilyName)
    {
        return impl::call_factory<AppDiagnosticInfo, IAppDiagnosticInfoStatics2>([&](IAppDiagnosticInfoStatics2 const& f) { return f.RequestInfoForPackageAsync(packageFamilyName); });
    }
    inline auto AppDiagnosticInfo::RequestInfoForAppAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::System::AppDiagnosticInfo>>(*)(IAppDiagnosticInfoStatics2 const&), AppDiagnosticInfo, IAppDiagnosticInfoStatics2>([](IAppDiagnosticInfoStatics2 const& f) { return f.RequestInfoForAppAsync(); });
    }
    inline auto AppDiagnosticInfo::RequestInfoForAppAsync(param::hstring const& appUserModelId)
    {
        return impl::call_factory<AppDiagnosticInfo, IAppDiagnosticInfoStatics2>([&](IAppDiagnosticInfoStatics2 const& f) { return f.RequestInfoForAppAsync(appUserModelId); });
    }
    inline AppUriHandlerHost::AppUriHandlerHost() :
        AppUriHandlerHost(impl::call_factory_cast<AppUriHandlerHost(*)(llm::OS::Foundation::IActivationFactory const&), AppUriHandlerHost>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<AppUriHandlerHost>(); }))
    {
    }
    inline AppUriHandlerHost::AppUriHandlerHost(param::hstring const& name) :
        AppUriHandlerHost(impl::call_factory<AppUriHandlerHost, IAppUriHandlerHostFactory>([&](IAppUriHandlerHostFactory const& f) { return f.CreateInstance(name); }))
    {
    }
    inline auto AppUriHandlerRegistrationManager::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::System::AppUriHandlerRegistrationManager(*)(IAppUriHandlerRegistrationManagerStatics const&), AppUriHandlerRegistrationManager, IAppUriHandlerRegistrationManagerStatics>([](IAppUriHandlerRegistrationManagerStatics const& f) { return f.GetDefault(); });
    }
    inline auto AppUriHandlerRegistrationManager::GetForUser(llm::OS::System::User const& user)
    {
        return impl::call_factory<AppUriHandlerRegistrationManager, IAppUriHandlerRegistrationManagerStatics>([&](IAppUriHandlerRegistrationManagerStatics const& f) { return f.GetForUser(user); });
    }
    inline auto AppUriHandlerRegistrationManager::GetForPackage(param::hstring const& packageFamilyName)
    {
        return impl::call_factory<AppUriHandlerRegistrationManager, IAppUriHandlerRegistrationManagerStatics2>([&](IAppUriHandlerRegistrationManagerStatics2 const& f) { return f.GetForPackage(packageFamilyName); });
    }
    inline auto AppUriHandlerRegistrationManager::GetForPackageForUser(param::hstring const& packageFamilyName, llm::OS::System::User const& user)
    {
        return impl::call_factory<AppUriHandlerRegistrationManager, IAppUriHandlerRegistrationManagerStatics2>([&](IAppUriHandlerRegistrationManagerStatics2 const& f) { return f.GetForPackageForUser(packageFamilyName, user); });
    }
    inline auto DateTimeSettings::SetSystemDateTime(llm::OS::Foundation::DateTime const& utcDateTime)
    {
        impl::call_factory<DateTimeSettings, IDateTimeSettingsStatics>([&](IDateTimeSettingsStatics const& f) { return f.SetSystemDateTime(utcDateTime); });
    }
    inline auto DispatcherQueue::GetForCurrentThread()
    {
        return impl::call_factory_cast<llm::OS::System::DispatcherQueue(*)(IDispatcherQueueStatics const&), DispatcherQueue, IDispatcherQueueStatics>([](IDispatcherQueueStatics const& f) { return f.GetForCurrentThread(); });
    }
    inline auto DispatcherQueueController::CreateOnDedicatedThread()
    {
        return impl::call_factory_cast<llm::OS::System::DispatcherQueueController(*)(IDispatcherQueueControllerStatics const&), DispatcherQueueController, IDispatcherQueueControllerStatics>([](IDispatcherQueueControllerStatics const& f) { return f.CreateOnDedicatedThread(); });
    }
    inline FolderLauncherOptions::FolderLauncherOptions() :
        FolderLauncherOptions(impl::call_factory_cast<FolderLauncherOptions(*)(llm::OS::Foundation::IActivationFactory const&), FolderLauncherOptions>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<FolderLauncherOptions>(); }))
    {
    }
    inline auto KnownUserProperties::DisplayName()
    {
        return impl::call_factory_cast<hstring(*)(IKnownUserPropertiesStatics const&), KnownUserProperties, IKnownUserPropertiesStatics>([](IKnownUserPropertiesStatics const& f) { return f.DisplayName(); });
    }
    inline auto KnownUserProperties::FirstName()
    {
        return impl::call_factory_cast<hstring(*)(IKnownUserPropertiesStatics const&), KnownUserProperties, IKnownUserPropertiesStatics>([](IKnownUserPropertiesStatics const& f) { return f.FirstName(); });
    }
    inline auto KnownUserProperties::LastName()
    {
        return impl::call_factory_cast<hstring(*)(IKnownUserPropertiesStatics const&), KnownUserProperties, IKnownUserPropertiesStatics>([](IKnownUserPropertiesStatics const& f) { return f.LastName(); });
    }
    inline auto KnownUserProperties::ProviderName()
    {
        return impl::call_factory_cast<hstring(*)(IKnownUserPropertiesStatics const&), KnownUserProperties, IKnownUserPropertiesStatics>([](IKnownUserPropertiesStatics const& f) { return f.ProviderName(); });
    }
    inline auto KnownUserProperties::AccountName()
    {
        return impl::call_factory_cast<hstring(*)(IKnownUserPropertiesStatics const&), KnownUserProperties, IKnownUserPropertiesStatics>([](IKnownUserPropertiesStatics const& f) { return f.AccountName(); });
    }
    inline auto KnownUserProperties::GuestHost()
    {
        return impl::call_factory_cast<hstring(*)(IKnownUserPropertiesStatics const&), KnownUserProperties, IKnownUserPropertiesStatics>([](IKnownUserPropertiesStatics const& f) { return f.GuestHost(); });
    }
    inline auto KnownUserProperties::PrincipalName()
    {
        return impl::call_factory_cast<hstring(*)(IKnownUserPropertiesStatics const&), KnownUserProperties, IKnownUserPropertiesStatics>([](IKnownUserPropertiesStatics const& f) { return f.PrincipalName(); });
    }
    inline auto KnownUserProperties::DomainName()
    {
        return impl::call_factory_cast<hstring(*)(IKnownUserPropertiesStatics const&), KnownUserProperties, IKnownUserPropertiesStatics>([](IKnownUserPropertiesStatics const& f) { return f.DomainName(); });
    }
    inline auto KnownUserProperties::SessionInitiationProtocolUri()
    {
        return impl::call_factory_cast<hstring(*)(IKnownUserPropertiesStatics const&), KnownUserProperties, IKnownUserPropertiesStatics>([](IKnownUserPropertiesStatics const& f) { return f.SessionInitiationProtocolUri(); });
    }
    inline auto KnownUserProperties::AgeEnforcementRegion()
    {
        return impl::call_factory_cast<hstring(*)(IKnownUserPropertiesStatics2 const&), KnownUserProperties, IKnownUserPropertiesStatics2>([](IKnownUserPropertiesStatics2 const& f) { return f.AgeEnforcementRegion(); });
    }
    inline auto Launcher::LaunchFileAsync(llm::OS::Storage::IStorageFile const& file)
    {
        return impl::call_factory<Launcher, ILauncherStatics>([&](ILauncherStatics const& f) { return f.LaunchFileAsync(file); });
    }
    inline auto Launcher::LaunchFileAsync(llm::OS::Storage::IStorageFile const& file, llm::OS::System::LauncherOptions const& options)
    {
        return impl::call_factory<Launcher, ILauncherStatics>([&](ILauncherStatics const& f) { return f.LaunchFileAsync(file, options); });
    }
    inline auto Launcher::LaunchUriAsync(llm::OS::Foundation::Uri const& uri)
    {
        return impl::call_factory<Launcher, ILauncherStatics>([&](ILauncherStatics const& f) { return f.LaunchUriAsync(uri); });
    }
    inline auto Launcher::LaunchUriAsync(llm::OS::Foundation::Uri const& uri, llm::OS::System::LauncherOptions const& options)
    {
        return impl::call_factory<Launcher, ILauncherStatics>([&](ILauncherStatics const& f) { return f.LaunchUriAsync(uri, options); });
    }
    inline auto Launcher::LaunchUriForResultsAsync(llm::OS::Foundation::Uri const& uri, llm::OS::System::LauncherOptions const& options)
    {
        return impl::call_factory<Launcher, ILauncherStatics2>([&](ILauncherStatics2 const& f) { return f.LaunchUriForResultsAsync(uri, options); });
    }
    inline auto Launcher::LaunchUriForResultsAsync(llm::OS::Foundation::Uri const& uri, llm::OS::System::LauncherOptions const& options, llm::OS::Foundation::Collections::ValueSet const& inputData)
    {
        return impl::call_factory<Launcher, ILauncherStatics2>([&](ILauncherStatics2 const& f) { return f.LaunchUriForResultsAsync(uri, options, inputData); });
    }
    inline auto Launcher::LaunchUriAsync(llm::OS::Foundation::Uri const& uri, llm::OS::System::LauncherOptions const& options, llm::OS::Foundation::Collections::ValueSet const& inputData)
    {
        return impl::call_factory<Launcher, ILauncherStatics2>([&](ILauncherStatics2 const& f) { return f.LaunchUriAsync(uri, options, inputData); });
    }
    inline auto Launcher::QueryUriSupportAsync(llm::OS::Foundation::Uri const& uri, llm::OS::System::LaunchQuerySupportType const& launchQuerySupportType)
    {
        return impl::call_factory<Launcher, ILauncherStatics2>([&](ILauncherStatics2 const& f) { return f.QueryUriSupportAsync(uri, launchQuerySupportType); });
    }
    inline auto Launcher::QueryUriSupportAsync(llm::OS::Foundation::Uri const& uri, llm::OS::System::LaunchQuerySupportType const& launchQuerySupportType, param::hstring const& packageFamilyName)
    {
        return impl::call_factory<Launcher, ILauncherStatics2>([&](ILauncherStatics2 const& f) { return f.QueryUriSupportAsync(uri, launchQuerySupportType, packageFamilyName); });
    }
    inline auto Launcher::QueryFileSupportAsync(llm::OS::Storage::StorageFile const& file)
    {
        return impl::call_factory<Launcher, ILauncherStatics2>([&](ILauncherStatics2 const& f) { return f.QueryFileSupportAsync(file); });
    }
    inline auto Launcher::QueryFileSupportAsync(llm::OS::Storage::StorageFile const& file, param::hstring const& packageFamilyName)
    {
        return impl::call_factory<Launcher, ILauncherStatics2>([&](ILauncherStatics2 const& f) { return f.QueryFileSupportAsync(file, packageFamilyName); });
    }
    inline auto Launcher::FindUriSchemeHandlersAsync(param::hstring const& scheme)
    {
        return impl::call_factory<Launcher, ILauncherStatics2>([&](ILauncherStatics2 const& f) { return f.FindUriSchemeHandlersAsync(scheme); });
    }
    inline auto Launcher::FindUriSchemeHandlersAsync(param::hstring const& scheme, llm::OS::System::LaunchQuerySupportType const& launchQuerySupportType)
    {
        return impl::call_factory<Launcher, ILauncherStatics2>([&](ILauncherStatics2 const& f) { return f.FindUriSchemeHandlersAsync(scheme, launchQuerySupportType); });
    }
    inline auto Launcher::FindFileHandlersAsync(param::hstring const& extension)
    {
        return impl::call_factory<Launcher, ILauncherStatics2>([&](ILauncherStatics2 const& f) { return f.FindFileHandlersAsync(extension); });
    }
    inline auto Launcher::LaunchFolderAsync(llm::OS::Storage::IStorageFolder const& folder)
    {
        return impl::call_factory<Launcher, ILauncherStatics3>([&](ILauncherStatics3 const& f) { return f.LaunchFolderAsync(folder); });
    }
    inline auto Launcher::LaunchFolderAsync(llm::OS::Storage::IStorageFolder const& folder, llm::OS::System::FolderLauncherOptions const& options)
    {
        return impl::call_factory<Launcher, ILauncherStatics3>([&](ILauncherStatics3 const& f) { return f.LaunchFolderAsync(folder, options); });
    }
    inline auto Launcher::QueryAppUriSupportAsync(llm::OS::Foundation::Uri const& uri)
    {
        return impl::call_factory<Launcher, ILauncherStatics4>([&](ILauncherStatics4 const& f) { return f.QueryAppUriSupportAsync(uri); });
    }
    inline auto Launcher::QueryAppUriSupportAsync(llm::OS::Foundation::Uri const& uri, param::hstring const& packageFamilyName)
    {
        return impl::call_factory<Launcher, ILauncherStatics4>([&](ILauncherStatics4 const& f) { return f.QueryAppUriSupportAsync(uri, packageFamilyName); });
    }
    inline auto Launcher::FindAppUriHandlersAsync(llm::OS::Foundation::Uri const& uri)
    {
        return impl::call_factory<Launcher, ILauncherStatics4>([&](ILauncherStatics4 const& f) { return f.FindAppUriHandlersAsync(uri); });
    }
    inline auto Launcher::LaunchUriForUserAsync(llm::OS::System::User const& user, llm::OS::Foundation::Uri const& uri)
    {
        return impl::call_factory<Launcher, ILauncherStatics4>([&](ILauncherStatics4 const& f) { return f.LaunchUriForUserAsync(user, uri); });
    }
    inline auto Launcher::LaunchUriForUserAsync(llm::OS::System::User const& user, llm::OS::Foundation::Uri const& uri, llm::OS::System::LauncherOptions const& options)
    {
        return impl::call_factory<Launcher, ILauncherStatics4>([&](ILauncherStatics4 const& f) { return f.LaunchUriForUserAsync(user, uri, options); });
    }
    inline auto Launcher::LaunchUriForUserAsync(llm::OS::System::User const& user, llm::OS::Foundation::Uri const& uri, llm::OS::System::LauncherOptions const& options, llm::OS::Foundation::Collections::ValueSet const& inputData)
    {
        return impl::call_factory<Launcher, ILauncherStatics4>([&](ILauncherStatics4 const& f) { return f.LaunchUriForUserAsync(user, uri, options, inputData); });
    }
    inline auto Launcher::LaunchUriForResultsForUserAsync(llm::OS::System::User const& user, llm::OS::Foundation::Uri const& uri, llm::OS::System::LauncherOptions const& options)
    {
        return impl::call_factory<Launcher, ILauncherStatics4>([&](ILauncherStatics4 const& f) { return f.LaunchUriForResultsForUserAsync(user, uri, options); });
    }
    inline auto Launcher::LaunchUriForResultsForUserAsync(llm::OS::System::User const& user, llm::OS::Foundation::Uri const& uri, llm::OS::System::LauncherOptions const& options, llm::OS::Foundation::Collections::ValueSet const& inputData)
    {
        return impl::call_factory<Launcher, ILauncherStatics4>([&](ILauncherStatics4 const& f) { return f.LaunchUriForResultsForUserAsync(user, uri, options, inputData); });
    }
    inline auto Launcher::LaunchFolderPathAsync(param::hstring const& path)
    {
        return impl::call_factory<Launcher, ILauncherStatics5>([&](ILauncherStatics5 const& f) { return f.LaunchFolderPathAsync(path); });
    }
    inline auto Launcher::LaunchFolderPathAsync(param::hstring const& path, llm::OS::System::FolderLauncherOptions const& options)
    {
        return impl::call_factory<Launcher, ILauncherStatics5>([&](ILauncherStatics5 const& f) { return f.LaunchFolderPathAsync(path, options); });
    }
    inline auto Launcher::LaunchFolderPathForUserAsync(llm::OS::System::User const& user, param::hstring const& path)
    {
        return impl::call_factory<Launcher, ILauncherStatics5>([&](ILauncherStatics5 const& f) { return f.LaunchFolderPathForUserAsync(user, path); });
    }
    inline auto Launcher::LaunchFolderPathForUserAsync(llm::OS::System::User const& user, param::hstring const& path, llm::OS::System::FolderLauncherOptions const& options)
    {
        return impl::call_factory<Launcher, ILauncherStatics5>([&](ILauncherStatics5 const& f) { return f.LaunchFolderPathForUserAsync(user, path, options); });
    }
    inline LauncherOptions::LauncherOptions() :
        LauncherOptions(impl::call_factory_cast<LauncherOptions(*)(llm::OS::Foundation::IActivationFactory const&), LauncherOptions>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<LauncherOptions>(); }))
    {
    }
    inline auto MemoryManager::AppMemoryUsage()
    {
        return impl::call_factory_cast<uint64_t(*)(IMemoryManagerStatics const&), MemoryManager, IMemoryManagerStatics>([](IMemoryManagerStatics const& f) { return f.AppMemoryUsage(); });
    }
    inline auto MemoryManager::AppMemoryUsageLimit()
    {
        return impl::call_factory_cast<uint64_t(*)(IMemoryManagerStatics const&), MemoryManager, IMemoryManagerStatics>([](IMemoryManagerStatics const& f) { return f.AppMemoryUsageLimit(); });
    }
    inline auto MemoryManager::AppMemoryUsageLevel()
    {
        return impl::call_factory_cast<llm::OS::System::AppMemoryUsageLevel(*)(IMemoryManagerStatics const&), MemoryManager, IMemoryManagerStatics>([](IMemoryManagerStatics const& f) { return f.AppMemoryUsageLevel(); });
    }
    inline auto MemoryManager::AppMemoryUsageIncreased(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        return impl::call_factory<MemoryManager, IMemoryManagerStatics>([&](IMemoryManagerStatics const& f) { return f.AppMemoryUsageIncreased(handler); });
    }
    inline MemoryManager::AppMemoryUsageIncreased_revoker MemoryManager::AppMemoryUsageIncreased(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        auto f = get_activation_factory<MemoryManager, llm::OS::System::IMemoryManagerStatics>();
        return { f, f.AppMemoryUsageIncreased(handler) };
    }
    inline auto MemoryManager::AppMemoryUsageIncreased(llm::event_token const& token)
    {
        impl::call_factory<MemoryManager, IMemoryManagerStatics>([&](IMemoryManagerStatics const& f) { return f.AppMemoryUsageIncreased(token); });
    }
    inline auto MemoryManager::AppMemoryUsageDecreased(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        return impl::call_factory<MemoryManager, IMemoryManagerStatics>([&](IMemoryManagerStatics const& f) { return f.AppMemoryUsageDecreased(handler); });
    }
    inline MemoryManager::AppMemoryUsageDecreased_revoker MemoryManager::AppMemoryUsageDecreased(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        auto f = get_activation_factory<MemoryManager, llm::OS::System::IMemoryManagerStatics>();
        return { f, f.AppMemoryUsageDecreased(handler) };
    }
    inline auto MemoryManager::AppMemoryUsageDecreased(llm::event_token const& token)
    {
        impl::call_factory<MemoryManager, IMemoryManagerStatics>([&](IMemoryManagerStatics const& f) { return f.AppMemoryUsageDecreased(token); });
    }
    inline auto MemoryManager::AppMemoryUsageLimitChanging(llm::OS::Foundation::EventHandler<llm::OS::System::AppMemoryUsageLimitChangingEventArgs> const& handler)
    {
        return impl::call_factory<MemoryManager, IMemoryManagerStatics>([&](IMemoryManagerStatics const& f) { return f.AppMemoryUsageLimitChanging(handler); });
    }
    inline MemoryManager::AppMemoryUsageLimitChanging_revoker MemoryManager::AppMemoryUsageLimitChanging(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::System::AppMemoryUsageLimitChangingEventArgs> const& handler)
    {
        auto f = get_activation_factory<MemoryManager, llm::OS::System::IMemoryManagerStatics>();
        return { f, f.AppMemoryUsageLimitChanging(handler) };
    }
    inline auto MemoryManager::AppMemoryUsageLimitChanging(llm::event_token const& token)
    {
        impl::call_factory<MemoryManager, IMemoryManagerStatics>([&](IMemoryManagerStatics const& f) { return f.AppMemoryUsageLimitChanging(token); });
    }
    inline auto MemoryManager::GetAppMemoryReport()
    {
        return impl::call_factory_cast<llm::OS::System::AppMemoryReport(*)(IMemoryManagerStatics2 const&), MemoryManager, IMemoryManagerStatics2>([](IMemoryManagerStatics2 const& f) { return f.GetAppMemoryReport(); });
    }
    inline auto MemoryManager::GetProcessMemoryReport()
    {
        return impl::call_factory_cast<llm::OS::System::ProcessMemoryReport(*)(IMemoryManagerStatics2 const&), MemoryManager, IMemoryManagerStatics2>([](IMemoryManagerStatics2 const& f) { return f.GetProcessMemoryReport(); });
    }
    inline auto MemoryManager::TrySetAppMemoryUsageLimit(uint64_t value)
    {
        return impl::call_factory<MemoryManager, IMemoryManagerStatics3>([&](IMemoryManagerStatics3 const& f) { return f.TrySetAppMemoryUsageLimit(value); });
    }
    inline auto MemoryManager::ExpectedAppMemoryUsageLimit()
    {
        return impl::call_factory_cast<uint64_t(*)(IMemoryManagerStatics4 const&), MemoryManager, IMemoryManagerStatics4>([](IMemoryManagerStatics4 const& f) { return f.ExpectedAppMemoryUsageLimit(); });
    }
    inline auto ProcessLauncher::RunToCompletionAsync(param::hstring const& fileName, param::hstring const& args)
    {
        return impl::call_factory<ProcessLauncher, IProcessLauncherStatics>([&](IProcessLauncherStatics const& f) { return f.RunToCompletionAsync(fileName, args); });
    }
    inline auto ProcessLauncher::RunToCompletionAsync(param::hstring const& fileName, param::hstring const& args, llm::OS::System::ProcessLauncherOptions const& options)
    {
        return impl::call_factory<ProcessLauncher, IProcessLauncherStatics>([&](IProcessLauncherStatics const& f) { return f.RunToCompletionAsync(fileName, args, options); });
    }
    inline ProcessLauncherOptions::ProcessLauncherOptions() :
        ProcessLauncherOptions(impl::call_factory_cast<ProcessLauncherOptions(*)(llm::OS::Foundation::IActivationFactory const&), ProcessLauncherOptions>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<ProcessLauncherOptions>(); }))
    {
    }
    inline auto RemoteLauncher::LaunchUriAsync(llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest const& remoteSystemConnectionRequest, llm::OS::Foundation::Uri const& uri)
    {
        return impl::call_factory<RemoteLauncher, IRemoteLauncherStatics>([&](IRemoteLauncherStatics const& f) { return f.LaunchUriAsync(remoteSystemConnectionRequest, uri); });
    }
    inline auto RemoteLauncher::LaunchUriAsync(llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest const& remoteSystemConnectionRequest, llm::OS::Foundation::Uri const& uri, llm::OS::System::RemoteLauncherOptions const& options)
    {
        return impl::call_factory<RemoteLauncher, IRemoteLauncherStatics>([&](IRemoteLauncherStatics const& f) { return f.LaunchUriAsync(remoteSystemConnectionRequest, uri, options); });
    }
    inline auto RemoteLauncher::LaunchUriAsync(llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest const& remoteSystemConnectionRequest, llm::OS::Foundation::Uri const& uri, llm::OS::System::RemoteLauncherOptions const& options, llm::OS::Foundation::Collections::ValueSet const& inputData)
    {
        return impl::call_factory<RemoteLauncher, IRemoteLauncherStatics>([&](IRemoteLauncherStatics const& f) { return f.LaunchUriAsync(remoteSystemConnectionRequest, uri, options, inputData); });
    }
    inline RemoteLauncherOptions::RemoteLauncherOptions() :
        RemoteLauncherOptions(impl::call_factory_cast<RemoteLauncherOptions(*)(llm::OS::Foundation::IActivationFactory const&), RemoteLauncherOptions>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<RemoteLauncherOptions>(); }))
    {
    }
    inline auto ShutdownManager::BeginShutdown(llm::OS::System::ShutdownKind const& shutdownKind, llm::OS::Foundation::TimeSpan const& timeout)
    {
        impl::call_factory<ShutdownManager, IShutdownManagerStatics>([&](IShutdownManagerStatics const& f) { return f.BeginShutdown(shutdownKind, timeout); });
    }
    inline auto ShutdownManager::CancelShutdown()
    {
        impl::call_factory_cast<void(*)(IShutdownManagerStatics const&), ShutdownManager, IShutdownManagerStatics>([](IShutdownManagerStatics const& f) { return f.CancelShutdown(); });
    }
    inline auto ShutdownManager::IsPowerStateSupported(llm::OS::System::PowerState const& powerState)
    {
        return impl::call_factory<ShutdownManager, IShutdownManagerStatics2>([&](IShutdownManagerStatics2 const& f) { return f.IsPowerStateSupported(powerState); });
    }
    inline auto ShutdownManager::EnterPowerState(llm::OS::System::PowerState const& powerState)
    {
        impl::call_factory<ShutdownManager, IShutdownManagerStatics2>([&](IShutdownManagerStatics2 const& f) { return f.EnterPowerState(powerState); });
    }
    inline auto ShutdownManager::EnterPowerState(llm::OS::System::PowerState const& powerState, llm::OS::Foundation::TimeSpan const& wakeUpAfter)
    {
        impl::call_factory<ShutdownManager, IShutdownManagerStatics2>([&](IShutdownManagerStatics2 const& f) { return f.EnterPowerState(powerState, wakeUpAfter); });
    }
    inline auto TimeZoneSettings::CurrentTimeZoneDisplayName()
    {
        return impl::call_factory_cast<hstring(*)(ITimeZoneSettingsStatics const&), TimeZoneSettings, ITimeZoneSettingsStatics>([](ITimeZoneSettingsStatics const& f) { return f.CurrentTimeZoneDisplayName(); });
    }
    inline auto TimeZoneSettings::SupportedTimeZoneDisplayNames()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<hstring>(*)(ITimeZoneSettingsStatics const&), TimeZoneSettings, ITimeZoneSettingsStatics>([](ITimeZoneSettingsStatics const& f) { return f.SupportedTimeZoneDisplayNames(); });
    }
    inline auto TimeZoneSettings::CanChangeTimeZone()
    {
        return impl::call_factory_cast<bool(*)(ITimeZoneSettingsStatics const&), TimeZoneSettings, ITimeZoneSettingsStatics>([](ITimeZoneSettingsStatics const& f) { return f.CanChangeTimeZone(); });
    }
    inline auto TimeZoneSettings::ChangeTimeZoneByDisplayName(param::hstring const& timeZoneDisplayName)
    {
        impl::call_factory<TimeZoneSettings, ITimeZoneSettingsStatics>([&](ITimeZoneSettingsStatics const& f) { return f.ChangeTimeZoneByDisplayName(timeZoneDisplayName); });
    }
    inline auto TimeZoneSettings::AutoUpdateTimeZoneAsync(llm::OS::Foundation::TimeSpan const& timeout)
    {
        return impl::call_factory<TimeZoneSettings, ITimeZoneSettingsStatics2>([&](ITimeZoneSettingsStatics2 const& f) { return f.AutoUpdateTimeZoneAsync(timeout); });
    }
    inline auto User::CreateWatcher()
    {
        return impl::call_factory_cast<llm::OS::System::UserWatcher(*)(IUserStatics const&), User, IUserStatics>([](IUserStatics const& f) { return f.CreateWatcher(); });
    }
    inline auto User::FindAllAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::System::User>>(*)(IUserStatics const&), User, IUserStatics>([](IUserStatics const& f) { return f.FindAllAsync(); });
    }
    inline auto User::FindAllAsync(llm::OS::System::UserType const& type)
    {
        return impl::call_factory<User, IUserStatics>([&](IUserStatics const& f) { return f.FindAllAsync(type); });
    }
    inline auto User::FindAllAsync(llm::OS::System::UserType const& type, llm::OS::System::UserAuthenticationStatus const& status)
    {
        return impl::call_factory<User, IUserStatics>([&](IUserStatics const& f) { return f.FindAllAsync(type, status); });
    }
    inline auto User::GetFromId(param::hstring const& nonRoamableId)
    {
        return impl::call_factory<User, IUserStatics>([&](IUserStatics const& f) { return f.GetFromId(nonRoamableId); });
    }
    inline auto User::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::System::User(*)(IUserStatics2 const&), User, IUserStatics2>([](IUserStatics2 const& f) { return f.GetDefault(); });
    }
    inline auto UserDeviceAssociation::FindUserFromDeviceId(param::hstring const& deviceId)
    {
        return impl::call_factory<UserDeviceAssociation, IUserDeviceAssociationStatics>([&](IUserDeviceAssociationStatics const& f) { return f.FindUserFromDeviceId(deviceId); });
    }
    inline auto UserDeviceAssociation::UserDeviceAssociationChanged(llm::OS::Foundation::EventHandler<llm::OS::System::UserDeviceAssociationChangedEventArgs> const& handler)
    {
        return impl::call_factory<UserDeviceAssociation, IUserDeviceAssociationStatics>([&](IUserDeviceAssociationStatics const& f) { return f.UserDeviceAssociationChanged(handler); });
    }
    inline UserDeviceAssociation::UserDeviceAssociationChanged_revoker UserDeviceAssociation::UserDeviceAssociationChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::System::UserDeviceAssociationChangedEventArgs> const& handler)
    {
        auto f = get_activation_factory<UserDeviceAssociation, llm::OS::System::IUserDeviceAssociationStatics>();
        return { f, f.UserDeviceAssociationChanged(handler) };
    }
    inline auto UserDeviceAssociation::UserDeviceAssociationChanged(llm::event_token const& token)
    {
        impl::call_factory<UserDeviceAssociation, IUserDeviceAssociationStatics>([&](IUserDeviceAssociationStatics const& f) { return f.UserDeviceAssociationChanged(token); });
    }
    inline UserPicker::UserPicker() :
        UserPicker(impl::call_factory_cast<UserPicker(*)(llm::OS::Foundation::IActivationFactory const&), UserPicker>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<UserPicker>(); }))
    {
    }
    inline auto UserPicker::IsSupported()
    {
        return impl::call_factory_cast<bool(*)(IUserPickerStatics const&), UserPicker, IUserPickerStatics>([](IUserPickerStatics const& f) { return f.IsSupported(); });
    }
    template <typename L> DispatcherQueueHandler::DispatcherQueueHandler(L handler) :
        DispatcherQueueHandler(impl::make_delegate<DispatcherQueueHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> DispatcherQueueHandler::DispatcherQueueHandler(F* handler) :
        DispatcherQueueHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> DispatcherQueueHandler::DispatcherQueueHandler(O* object, M method) :
        DispatcherQueueHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> DispatcherQueueHandler::DispatcherQueueHandler(com_ptr<O>&& object, M method) :
        DispatcherQueueHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> DispatcherQueueHandler::DispatcherQueueHandler(weak_ref<O>&& object, M method) :
        DispatcherQueueHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto DispatcherQueueHandler::operator()() const
    {
        check_hresult((*(impl::abi_t<DispatcherQueueHandler>**)this)->Invoke());
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::System::IAppActivationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppDiagnosticInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppDiagnosticInfo2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppDiagnosticInfo3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppDiagnosticInfoStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppDiagnosticInfoStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppDiagnosticInfoWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppDiagnosticInfoWatcherEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppExecutionStateChangeResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppMemoryReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppMemoryReport2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppMemoryUsageLimitChangingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppResourceGroupBackgroundTaskReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppResourceGroupInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppResourceGroupInfo2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppResourceGroupInfoWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppResourceGroupInfoWatcherEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppResourceGroupInfoWatcherExecutionStateChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppResourceGroupMemoryReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppResourceGroupStateReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppUriHandlerHost> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppUriHandlerHost2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppUriHandlerHostFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppUriHandlerRegistration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppUriHandlerRegistration2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppUriHandlerRegistrationManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppUriHandlerRegistrationManager2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppUriHandlerRegistrationManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IAppUriHandlerRegistrationManagerStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IDateTimeSettingsStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IDispatcherQueue> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IDispatcherQueue2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IDispatcherQueueController> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IDispatcherQueueControllerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IDispatcherQueueShutdownStartingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IDispatcherQueueStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IDispatcherQueueTimer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IFolderLauncherOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IKnownUserPropertiesStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IKnownUserPropertiesStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::ILaunchUriResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::ILauncherOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::ILauncherOptions2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::ILauncherOptions3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::ILauncherOptions4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::ILauncherStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::ILauncherStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::ILauncherStatics3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::ILauncherStatics4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::ILauncherStatics5> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::ILauncherUIOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::ILauncherViewOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IMemoryManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IMemoryManagerStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IMemoryManagerStatics3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IMemoryManagerStatics4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IProcessLauncherOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IProcessLauncherResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IProcessLauncherStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IProcessMemoryReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IProtocolForResultsOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IRemoteLauncherOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IRemoteLauncherStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IShutdownManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IShutdownManagerStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::ITimeZoneSettingsStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::ITimeZoneSettingsStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IUser> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IUser2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IUserAuthenticationStatusChangeDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IUserAuthenticationStatusChangingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IUserChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IUserChangedEventArgs2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IUserDeviceAssociationChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IUserDeviceAssociationStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IUserPicker> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IUserPickerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IUserStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IUserStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::IUserWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::AppActivationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::AppDiagnosticInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::AppDiagnosticInfoWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::AppDiagnosticInfoWatcherEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::AppExecutionStateChangeResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::AppMemoryReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::AppMemoryUsageLimitChangingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::AppResourceGroupBackgroundTaskReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::AppResourceGroupInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::AppResourceGroupInfoWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::AppResourceGroupInfoWatcherEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::AppResourceGroupInfoWatcherExecutionStateChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::AppResourceGroupMemoryReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::AppResourceGroupStateReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::AppUriHandlerHost> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::AppUriHandlerRegistration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::AppUriHandlerRegistrationManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::DateTimeSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::DispatcherQueue> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::DispatcherQueueController> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::DispatcherQueueShutdownStartingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::DispatcherQueueTimer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::FolderLauncherOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::KnownUserProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::LaunchUriResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Launcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::LauncherOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::LauncherUIOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::MemoryManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::ProcessLauncher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::ProcessLauncherOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::ProcessLauncherResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::ProcessMemoryReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::ProtocolForResultsOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteLauncher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteLauncherOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::ShutdownManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::TimeZoneSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::User> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserAuthenticationStatusChangeDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserAuthenticationStatusChangingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserDeviceAssociation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserDeviceAssociationChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserPicker> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::UserWatcher> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}

LLM_EXPORT namespace winrt
{
    [[nodiscard]] inline auto resume_foreground(
        Windows::System::DispatcherQueue const& dispatcher,
        Windows::System::DispatcherQueuePriority const priority = Windows::System::DispatcherQueuePriority::Normal) noexcept
    {
        struct awaitable
        {
            awaitable(Windows::System::DispatcherQueue const& dispatcher, Windows::System::DispatcherQueuePriority const priority) noexcept :
                m_dispatcher(dispatcher),
                m_priority(priority)
            {
            }

            bool await_ready() const noexcept
            {
                return false;
            }

            bool await_resume() const noexcept
            {
                return m_queued;
            }

            bool await_suspend(impl::coroutine_handle<> handle)
            {
                return m_dispatcher.TryEnqueue(m_priority, [handle, this]
                    {
                        m_queued = true;
                        handle();
                    });
            }

        private:
            Windows::System::DispatcherQueue const& m_dispatcher;
            Windows::System::DispatcherQueuePriority const m_priority;
            bool m_queued{};
        };

        return awaitable{ dispatcher, priority };
    };

#ifdef LLM_IMPL_COROUTINES
    inline auto operator co_await(Windows::System::DispatcherQueue const& dispatcher)
    {
        return resume_foreground(dispatcher);
    }
#endif
}
#endif
