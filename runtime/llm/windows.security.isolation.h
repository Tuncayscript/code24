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
#ifndef LLM_OS_Security_Isolation_H
#define LLM_OS_Security_Isolation_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Security.Isolation.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironment<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironment)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentStartProcessResult>) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironment<D>::StartProcessSilentlyAsync(param::hstring const& hostExePath, param::hstring const& arguments, llm::OS::Security::Isolation::IsolatedWindowsEnvironmentActivator const& activator) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironment)->StartProcessSilentlyAsync(*(void**)(&hostExePath), *(void**)(&arguments), static_cast<int32_t>(activator), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentStartProcessResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentStartProcessResult>) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironment<D>::StartProcessSilentlyAsync(param::hstring const& hostExePath, param::hstring const& arguments, llm::OS::Security::Isolation::IsolatedWindowsEnvironmentActivator const& activator, llm::OS::Security::Isolation::IsolatedWindowsEnvironmentTelemetryParameters const& telemetryParameters) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironment)->StartProcessSilentlyWithTelemetryAsync(*(void**)(&hostExePath), *(void**)(&arguments), static_cast<int32_t>(activator), *(void**)(&telemetryParameters), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentStartProcessResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFolderResult>) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironment<D>::ShareFolderAsync(param::hstring const& hostFolder, llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFolderRequestOptions const& requestOptions) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironment)->ShareFolderAsync(*(void**)(&hostFolder), *(void**)(&requestOptions), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFolderResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFolderResult>) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironment<D>::ShareFolderAsync(param::hstring const& hostFolder, llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFolderRequestOptions const& requestOptions, llm::OS::Security::Isolation::IsolatedWindowsEnvironmentTelemetryParameters const& telemetryParameters) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironment)->ShareFolderWithTelemetryAsync(*(void**)(&hostFolder), *(void**)(&requestOptions), *(void**)(&telemetryParameters), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFolderResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentLaunchFileResult>) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironment<D>::LaunchFileWithUIAsync(param::hstring const& appExePath, param::hstring const& argumentsTemplate, param::hstring const& filePath) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironment)->LaunchFileWithUIAsync(*(void**)(&appExePath), *(void**)(&argumentsTemplate), *(void**)(&filePath), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentLaunchFileResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentLaunchFileResult>) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironment<D>::LaunchFileWithUIAsync(param::hstring const& appExePath, param::hstring const& argumentsTemplate, param::hstring const& filePath, llm::OS::Security::Isolation::IsolatedWindowsEnvironmentTelemetryParameters const& telemetryParameters) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironment)->LaunchFileWithUIAndTelemetryAsync(*(void**)(&appExePath), *(void**)(&argumentsTemplate), *(void**)(&filePath), *(void**)(&telemetryParameters), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentLaunchFileResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironment<D>::TerminateAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironment)->TerminateAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironment<D>::TerminateAsync(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentTelemetryParameters const& telemetryParameters) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironment)->TerminateWithTelemetryAsync(*(void**)(&telemetryParameters), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironment<D>::RegisterMessageReceiver(llm::guid const& receiverId, llm::OS::Security::Isolation::MessageReceivedCallback const& messageReceivedCallback) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironment)->RegisterMessageReceiver(impl::bind_in(receiverId), *(void**)(&messageReceivedCallback)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironment<D>::UnregisterMessageReceiver(llm::guid const& receiverId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironment)->UnregisterMessageReceiver(impl::bind_in(receiverId)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentPostMessageResult>) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironment2<D>::PostMessageToReceiverAsync(llm::guid const& receiverId, param::async_iterable<llm::OS::Foundation::IInspectable> const& message) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironment2)->PostMessageToReceiverAsync(impl::bind_in(receiverId), *(void**)(&message), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentPostMessageResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentPostMessageResult>) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironment2<D>::PostMessageToReceiverAsync(llm::guid const& receiverId, param::async_iterable<llm::OS::Foundation::IInspectable> const& message, llm::OS::Security::Isolation::IsolatedWindowsEnvironmentTelemetryParameters const& telemetryParameters) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironment2)->PostMessageToReceiverWithTelemetryAsync(impl::bind_in(receiverId), *(void**)(&message), *(void**)(&telemetryParameters), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentPostMessageResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentUserInfo) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironment3<D>::GetUserInfo() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironment3)->GetUserInfo(&result));
        return llm::OS::Security::Isolation::IsolatedWindowsEnvironmentUserInfo{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFileResult>) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironment3<D>::ShareFileAsync(param::hstring const& filePath, llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFileRequestOptions const& options) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironment3)->ShareFileAsync(*(void**)(&filePath), *(void**)(&options), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFileResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFileResult>) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironment3<D>::ShareFileAsync(param::hstring const& filePath, llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFileRequestOptions const& options, llm::OS::Security::Isolation::IsolatedWindowsEnvironmentTelemetryParameters const& telemetryParameters) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironment3)->ShareFileWithTelemetryAsync(*(void**)(&filePath), *(void**)(&options), *(void**)(&telemetryParameters), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFileResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironment4<D>::ChangePriority(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreationPriority const& Priority) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironment4)->ChangePriority(static_cast<int32_t>(Priority)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreateStatus) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentCreateResult<D>::Status() const
    {
        llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreateStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentCreateResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentCreateResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentCreateResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Isolation::IsolatedWindowsEnvironment) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentCreateResult<D>::Environment() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentCreateResult)->get_Environment(&value));
        return llm::OS::Security::Isolation::IsolatedWindowsEnvironment{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentCreateResult2<D>::ChangeCreationPriority(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreationPriority const& priority) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentCreateResult2)->ChangeCreationPriority(static_cast<int32_t>(priority)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreateResult, llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreateProgress>) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentFactory<D>::CreateAsync(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentOptions const& options) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentFactory)->CreateAsync(*(void**)(&options), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreateResult, llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreateProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreateResult, llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreateProgress>) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentFactory<D>::CreateAsync(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentOptions const& options, llm::OS::Security::Isolation::IsolatedWindowsEnvironmentTelemetryParameters const& telemetryParameters) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentFactory)->CreateWithTelemetryAsync(*(void**)(&options), *(void**)(&telemetryParameters), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreateResult, llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreateProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Isolation::IsolatedWindowsEnvironment) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentFactory<D>::GetById(param::hstring const& environmentId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentFactory)->GetById(*(void**)(&environmentId), &result));
        return llm::OS::Security::Isolation::IsolatedWindowsEnvironment{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Isolation::IsolatedWindowsEnvironment>) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentFactory<D>::FindByOwnerId(param::hstring const& environmentOwnerId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentFactory)->FindByOwnerId(*(void**)(&environmentOwnerId), &result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Isolation::IsolatedWindowsEnvironment>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentFile<D>::Id() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentFile)->get_Id(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentFile<D>::HostPath() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentFile)->get_HostPath(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentFile<D>::Close() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentFile)->Close());
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentFile2<D>::GuestPath() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentFile2)->get_GuestPath(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentFile2<D>::IsReadOnly() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentFile2)->get_IsReadOnly(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentHostStatics<D>::IsReady() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentHostStatics)->get_IsReady(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentHostError>) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentHostStatics<D>::HostErrors() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentHostStatics)->get_HostErrors(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentHostError>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentLaunchFileStatus) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentLaunchFileResult<D>::Status() const
    {
        llm::OS::Security::Isolation::IsolatedWindowsEnvironmentLaunchFileStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentLaunchFileResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentLaunchFileResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentLaunchFileResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentFile) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentLaunchFileResult<D>::File() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentLaunchFileResult)->get_File(&value));
        return llm::OS::Security::Isolation::IsolatedWindowsEnvironmentFile{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions<D>::EnvironmentOwnerId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions)->get_EnvironmentOwnerId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions<D>::EnvironmentOwnerId(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions)->put_EnvironmentOwnerId(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentAllowedClipboardFormats) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions<D>::AllowedClipboardFormats() const
    {
        llm::OS::Security::Isolation::IsolatedWindowsEnvironmentAllowedClipboardFormats value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions)->get_AllowedClipboardFormats(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions<D>::AllowedClipboardFormats(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentAllowedClipboardFormats const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions)->put_AllowedClipboardFormats(static_cast<uint32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentClipboardCopyPasteDirections) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions<D>::ClipboardCopyPasteDirections() const
    {
        llm::OS::Security::Isolation::IsolatedWindowsEnvironmentClipboardCopyPasteDirections value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions)->get_ClipboardCopyPasteDirections(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions<D>::ClipboardCopyPasteDirections(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentClipboardCopyPasteDirections const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions)->put_ClipboardCopyPasteDirections(static_cast<uint32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentAvailablePrinters) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions<D>::AvailablePrinters() const
    {
        llm::OS::Security::Isolation::IsolatedWindowsEnvironmentAvailablePrinters value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions)->get_AvailablePrinters(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions<D>::AvailablePrinters(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentAvailablePrinters const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions)->put_AvailablePrinters(static_cast<uint32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions<D>::SharedHostFolderPath() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions)->get_SharedHostFolderPath(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions<D>::SharedFolderNameInEnvironment() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions)->get_SharedFolderNameInEnvironment(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions<D>::ShareHostFolderForUntrustedItems(param::hstring const& SharedHostFolderPath, param::hstring const& ShareFolderNameInEnvironment) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions)->ShareHostFolderForUntrustedItems(*(void**)(&SharedHostFolderPath), *(void**)(&ShareFolderNameInEnvironment)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions<D>::PersistUserProfile() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions)->get_PersistUserProfile(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions<D>::PersistUserProfile(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions)->put_PersistUserProfile(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions<D>::AllowGraphicsHardwareAcceleration() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions)->get_AllowGraphicsHardwareAcceleration(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions<D>::AllowGraphicsHardwareAcceleration(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions)->put_AllowGraphicsHardwareAcceleration(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions<D>::AllowCameraAndMicrophoneAccess() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions)->get_AllowCameraAndMicrophoneAccess(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions<D>::AllowCameraAndMicrophoneAccess(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions)->put_AllowCameraAndMicrophoneAccess(value));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions2<D>::WindowAnnotationOverride() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions2)->get_WindowAnnotationOverride(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions2<D>::WindowAnnotationOverride(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions2)->put_WindowAnnotationOverride(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentAllowedClipboardFormats) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions3<D>::AllowedClipboardFormatsToEnvironment() const
    {
        llm::OS::Security::Isolation::IsolatedWindowsEnvironmentAllowedClipboardFormats value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions3)->get_AllowedClipboardFormatsToEnvironment(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions3<D>::AllowedClipboardFormatsToEnvironment(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentAllowedClipboardFormats const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions3)->put_AllowedClipboardFormatsToEnvironment(static_cast<uint32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentAllowedClipboardFormats) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions3<D>::AllowedClipboardFormatsToHost() const
    {
        llm::OS::Security::Isolation::IsolatedWindowsEnvironmentAllowedClipboardFormats value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions3)->get_AllowedClipboardFormatsToHost(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions3<D>::AllowedClipboardFormatsToHost(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentAllowedClipboardFormats const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions3)->put_AllowedClipboardFormatsToHost(static_cast<uint32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreationPriority) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions3<D>::CreationPriority() const
    {
        llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreationPriority value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions3)->get_CreationPriority(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOptions3<D>::CreationPriority(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreationPriority const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions3)->put_CreationPriority(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOwnerRegistrationData<D>::ShareableFolders() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOwnerRegistrationData)->get_ShareableFolders(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOwnerRegistrationData<D>::ProcessesRunnableAsSystem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOwnerRegistrationData)->get_ProcessesRunnableAsSystem(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOwnerRegistrationData<D>::ProcessesRunnableAsUser() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOwnerRegistrationData)->get_ProcessesRunnableAsUser(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOwnerRegistrationData<D>::ActivationFileExtensions() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOwnerRegistrationData)->get_ActivationFileExtensions(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentOwnerRegistrationStatus) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOwnerRegistrationResult<D>::Status() const
    {
        llm::OS::Security::Isolation::IsolatedWindowsEnvironmentOwnerRegistrationStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOwnerRegistrationResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOwnerRegistrationResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOwnerRegistrationResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentOwnerRegistrationResult) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOwnerRegistrationStatics<D>::Register(param::hstring const& ownerName, llm::OS::Security::Isolation::IsolatedWindowsEnvironmentOwnerRegistrationData const& ownerRegistrationData) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOwnerRegistrationStatics)->Register(*(void**)(&ownerName), *(void**)(&ownerRegistrationData), &result));
        return llm::OS::Security::Isolation::IsolatedWindowsEnvironmentOwnerRegistrationResult{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentOwnerRegistrationStatics<D>::Unregister(param::hstring const& ownerName) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOwnerRegistrationStatics)->Unregister(*(void**)(&ownerName)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentPostMessageStatus) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentPostMessageResult<D>::Status() const
    {
        llm::OS::Security::Isolation::IsolatedWindowsEnvironmentPostMessageStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentPostMessageResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentPostMessageResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentPostMessageResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentProcessState) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentProcess<D>::State() const
    {
        llm::OS::Security::Isolation::IsolatedWindowsEnvironmentProcessState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentProcess)->get_State(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentProcess<D>::ExitCode() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentProcess)->get_ExitCode(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentProcess<D>::WaitForExit() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentProcess)->WaitForExit());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentProcess<D>::WaitForExitWithTimeout(uint32_t timeoutMilliseconds) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentProcess)->WaitForExitWithTimeout(timeoutMilliseconds));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentProcess<D>::WaitForExitAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentProcess)->WaitForExitAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentShareFileRequestOptions<D>::AllowWrite() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFileRequestOptions)->get_AllowWrite(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentShareFileRequestOptions<D>::AllowWrite(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFileRequestOptions)->put_AllowWrite(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFileStatus) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentShareFileResult<D>::Status() const
    {
        llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFileStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFileResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentShareFileResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFileResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentFile) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentShareFileResult<D>::File() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFileResult)->get_File(&value));
        return llm::OS::Security::Isolation::IsolatedWindowsEnvironmentFile{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentShareFolderRequestOptions<D>::AllowWrite() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFolderRequestOptions)->get_AllowWrite(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentShareFolderRequestOptions<D>::AllowWrite(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFolderRequestOptions)->put_AllowWrite(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFolderStatus) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentShareFolderResult<D>::Status() const
    {
        llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFolderStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFolderResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentShareFolderResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFolderResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentStartProcessStatus) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentStartProcessResult<D>::Status() const
    {
        llm::OS::Security::Isolation::IsolatedWindowsEnvironmentStartProcessStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentStartProcessResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentStartProcessResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentStartProcessResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentProcess) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentStartProcessResult<D>::Process() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentStartProcessResult)->get_Process(&value));
        return llm::OS::Security::Isolation::IsolatedWindowsEnvironmentProcess{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentTelemetryParameters<D>::CorrelationId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentTelemetryParameters)->get_CorrelationId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentTelemetryParameters<D>::CorrelationId(llm::guid const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentTelemetryParameters)->put_CorrelationId(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentUserInfo<D>::EnvironmentUserSid() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentUserInfo)->get_EnvironmentUserSid(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentUserInfo<D>::EnvironmentUserName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentUserInfo)->get_EnvironmentUserName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentUserInfo<D>::TryWaitForSignInAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentUserInfo)->TryWaitForSignInAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<bool, llm::OS::Security::Isolation::IsolatedWindowsEnvironmentSignInProgress>) consume_Windows_Security_Isolation_IIsolatedWindowsEnvironmentUserInfo2<D>::TryWaitForSignInWithProgressAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentUserInfo2)->TryWaitForSignInWithProgressAsync(&operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<bool, llm::OS::Security::Isolation::IsolatedWindowsEnvironmentSignInProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsHostMessengerStatics<D>::PostMessageToReceiver(llm::guid const& receiverId, param::vector_view<llm::OS::Foundation::IInspectable> const& message) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsHostMessengerStatics)->PostMessageToReceiver(impl::bind_in(receiverId), *(void**)(&message)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Security_Isolation_IIsolatedWindowsHostMessengerStatics<D>::GetFileId(param::hstring const& filePath) const
    {
        llm::guid result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsHostMessengerStatics)->GetFileId(*(void**)(&filePath), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsHostMessengerStatics2<D>::RegisterHostMessageReceiver(llm::guid const& receiverId, llm::OS::Security::Isolation::HostMessageReceivedCallback const& hostMessageReceivedCallback) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsHostMessengerStatics2)->RegisterHostMessageReceiver(impl::bind_in(receiverId), *(void**)(&hostMessageReceivedCallback)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Isolation_IIsolatedWindowsHostMessengerStatics2<D>::UnregisterHostMessageReceiver(llm::guid const& receiverId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Isolation::IIsolatedWindowsHostMessengerStatics2)->UnregisterHostMessageReceiver(impl::bind_in(receiverId)));
    }
    template <typename H> struct delegate<llm::OS::Security::Isolation::HostMessageReceivedCallback, H> final : implements_delegate<llm::OS::Security::Isolation::HostMessageReceivedCallback, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::Security::Isolation::HostMessageReceivedCallback, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(llm::guid receiverId, void* message) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::guid const*>(&receiverId), *reinterpret_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::IInspectable> const*>(&message));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H> struct delegate<llm::OS::Security::Isolation::MessageReceivedCallback, H> final : implements_delegate<llm::OS::Security::Isolation::MessageReceivedCallback, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::Security::Isolation::MessageReceivedCallback, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(llm::guid receiverId, void* message) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::guid const*>(&receiverId), *reinterpret_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::IInspectable> const*>(&message));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironment> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironment>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartProcessSilentlyAsync(void* hostExePath, void* arguments, int32_t activator, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentStartProcessResult>>(this->shim().StartProcessSilentlyAsync(*reinterpret_cast<hstring const*>(&hostExePath), *reinterpret_cast<hstring const*>(&arguments), *reinterpret_cast<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentActivator const*>(&activator)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartProcessSilentlyWithTelemetryAsync(void* hostExePath, void* arguments, int32_t activator, void* telemetryParameters, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentStartProcessResult>>(this->shim().StartProcessSilentlyAsync(*reinterpret_cast<hstring const*>(&hostExePath), *reinterpret_cast<hstring const*>(&arguments), *reinterpret_cast<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentActivator const*>(&activator), *reinterpret_cast<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentTelemetryParameters const*>(&telemetryParameters)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShareFolderAsync(void* hostFolder, void* requestOptions, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFolderResult>>(this->shim().ShareFolderAsync(*reinterpret_cast<hstring const*>(&hostFolder), *reinterpret_cast<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFolderRequestOptions const*>(&requestOptions)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShareFolderWithTelemetryAsync(void* hostFolder, void* requestOptions, void* telemetryParameters, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFolderResult>>(this->shim().ShareFolderAsync(*reinterpret_cast<hstring const*>(&hostFolder), *reinterpret_cast<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFolderRequestOptions const*>(&requestOptions), *reinterpret_cast<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentTelemetryParameters const*>(&telemetryParameters)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchFileWithUIAsync(void* appExePath, void* argumentsTemplate, void* filePath, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentLaunchFileResult>>(this->shim().LaunchFileWithUIAsync(*reinterpret_cast<hstring const*>(&appExePath), *reinterpret_cast<hstring const*>(&argumentsTemplate), *reinterpret_cast<hstring const*>(&filePath)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchFileWithUIAndTelemetryAsync(void* appExePath, void* argumentsTemplate, void* filePath, void* telemetryParameters, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentLaunchFileResult>>(this->shim().LaunchFileWithUIAsync(*reinterpret_cast<hstring const*>(&appExePath), *reinterpret_cast<hstring const*>(&argumentsTemplate), *reinterpret_cast<hstring const*>(&filePath), *reinterpret_cast<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentTelemetryParameters const*>(&telemetryParameters)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TerminateAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().TerminateAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TerminateWithTelemetryAsync(void* telemetryParameters, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().TerminateAsync(*reinterpret_cast<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentTelemetryParameters const*>(&telemetryParameters)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RegisterMessageReceiver(llm::guid receiverId, void* messageReceivedCallback) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RegisterMessageReceiver(*reinterpret_cast<llm::guid const*>(&receiverId), *reinterpret_cast<llm::OS::Security::Isolation::MessageReceivedCallback const*>(&messageReceivedCallback));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UnregisterMessageReceiver(llm::guid receiverId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UnregisterMessageReceiver(*reinterpret_cast<llm::guid const*>(&receiverId));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironment2> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironment2>
    {
        int32_t __stdcall PostMessageToReceiverAsync(llm::guid receiverId, void* message, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentPostMessageResult>>(this->shim().PostMessageToReceiverAsync(*reinterpret_cast<llm::guid const*>(&receiverId), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::IInspectable> const*>(&message)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PostMessageToReceiverWithTelemetryAsync(llm::guid receiverId, void* message, void* telemetryParameters, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentPostMessageResult>>(this->shim().PostMessageToReceiverAsync(*reinterpret_cast<llm::guid const*>(&receiverId), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::IInspectable> const*>(&message), *reinterpret_cast<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentTelemetryParameters const*>(&telemetryParameters)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironment3> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironment3>
    {
        int32_t __stdcall GetUserInfo(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentUserInfo>(this->shim().GetUserInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShareFileAsync(void* filePath, void* options, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFileResult>>(this->shim().ShareFileAsync(*reinterpret_cast<hstring const*>(&filePath), *reinterpret_cast<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFileRequestOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShareFileWithTelemetryAsync(void* filePath, void* options, void* telemetryParameters, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFileResult>>(this->shim().ShareFileAsync(*reinterpret_cast<hstring const*>(&filePath), *reinterpret_cast<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFileRequestOptions const*>(&options), *reinterpret_cast<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentTelemetryParameters const*>(&telemetryParameters)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironment4> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironment4>
    {
        int32_t __stdcall ChangePriority(int32_t Priority) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ChangePriority(*reinterpret_cast<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreationPriority const*>(&Priority));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentCreateResult> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentCreateResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreateStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Environment(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Isolation::IsolatedWindowsEnvironment>(this->shim().Environment());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentCreateResult2> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentCreateResult2>
    {
        int32_t __stdcall ChangeCreationPriority(int32_t priority) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ChangeCreationPriority(*reinterpret_cast<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreationPriority const*>(&priority));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentFactory> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentFactory>
    {
        int32_t __stdcall CreateAsync(void* options, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreateResult, llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreateProgress>>(this->shim().CreateAsync(*reinterpret_cast<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithTelemetryAsync(void* options, void* telemetryParameters, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreateResult, llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreateProgress>>(this->shim().CreateAsync(*reinterpret_cast<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentOptions const*>(&options), *reinterpret_cast<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentTelemetryParameters const*>(&telemetryParameters)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetById(void* environmentId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Security::Isolation::IsolatedWindowsEnvironment>(this->shim().GetById(*reinterpret_cast<hstring const*>(&environmentId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindByOwnerId(void* environmentOwnerId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Isolation::IsolatedWindowsEnvironment>>(this->shim().FindByOwnerId(*reinterpret_cast<hstring const*>(&environmentOwnerId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentFile> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentFile>
    {
        int32_t __stdcall get_Id(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HostPath(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().HostPath());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Close() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Close();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentFile2> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentFile2>
    {
        int32_t __stdcall get_GuestPath(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GuestPath());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsReadOnly(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsReadOnly());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentHostStatics> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentHostStatics>
    {
        int32_t __stdcall get_IsReady(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsReady());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HostErrors(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentHostError>>(this->shim().HostErrors());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentLaunchFileResult> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentLaunchFileResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentLaunchFileStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_File(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentFile>(this->shim().File());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions>
    {
        int32_t __stdcall get_EnvironmentOwnerId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().EnvironmentOwnerId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_EnvironmentOwnerId(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnvironmentOwnerId(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AllowedClipboardFormats(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentAllowedClipboardFormats>(this->shim().AllowedClipboardFormats());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AllowedClipboardFormats(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowedClipboardFormats(*reinterpret_cast<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentAllowedClipboardFormats const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ClipboardCopyPasteDirections(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentClipboardCopyPasteDirections>(this->shim().ClipboardCopyPasteDirections());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ClipboardCopyPasteDirections(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClipboardCopyPasteDirections(*reinterpret_cast<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentClipboardCopyPasteDirections const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AvailablePrinters(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentAvailablePrinters>(this->shim().AvailablePrinters());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AvailablePrinters(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AvailablePrinters(*reinterpret_cast<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentAvailablePrinters const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SharedHostFolderPath(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SharedHostFolderPath());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SharedFolderNameInEnvironment(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SharedFolderNameInEnvironment());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShareHostFolderForUntrustedItems(void* SharedHostFolderPath, void* ShareFolderNameInEnvironment) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShareHostFolderForUntrustedItems(*reinterpret_cast<hstring const*>(&SharedHostFolderPath), *reinterpret_cast<hstring const*>(&ShareFolderNameInEnvironment));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PersistUserProfile(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().PersistUserProfile());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PersistUserProfile(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PersistUserProfile(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AllowGraphicsHardwareAcceleration(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AllowGraphicsHardwareAcceleration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AllowGraphicsHardwareAcceleration(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowGraphicsHardwareAcceleration(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AllowCameraAndMicrophoneAccess(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AllowCameraAndMicrophoneAccess());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AllowCameraAndMicrophoneAccess(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowCameraAndMicrophoneAccess(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions2> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions2>
    {
        int32_t __stdcall get_WindowAnnotationOverride(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().WindowAnnotationOverride());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_WindowAnnotationOverride(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WindowAnnotationOverride(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions3> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions3>
    {
        int32_t __stdcall get_AllowedClipboardFormatsToEnvironment(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentAllowedClipboardFormats>(this->shim().AllowedClipboardFormatsToEnvironment());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AllowedClipboardFormatsToEnvironment(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowedClipboardFormatsToEnvironment(*reinterpret_cast<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentAllowedClipboardFormats const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AllowedClipboardFormatsToHost(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentAllowedClipboardFormats>(this->shim().AllowedClipboardFormatsToHost());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AllowedClipboardFormatsToHost(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowedClipboardFormatsToHost(*reinterpret_cast<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentAllowedClipboardFormats const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CreationPriority(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreationPriority>(this->shim().CreationPriority());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CreationPriority(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CreationPriority(*reinterpret_cast<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreationPriority const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOwnerRegistrationData> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOwnerRegistrationData>
    {
        int32_t __stdcall get_ShareableFolders(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().ShareableFolders());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProcessesRunnableAsSystem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().ProcessesRunnableAsSystem());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProcessesRunnableAsUser(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().ProcessesRunnableAsUser());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ActivationFileExtensions(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().ActivationFileExtensions());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOwnerRegistrationResult> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOwnerRegistrationResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentOwnerRegistrationStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
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
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOwnerRegistrationStatics> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOwnerRegistrationStatics>
    {
        int32_t __stdcall Register(void* ownerName, void* ownerRegistrationData, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentOwnerRegistrationResult>(this->shim().Register(*reinterpret_cast<hstring const*>(&ownerName), *reinterpret_cast<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentOwnerRegistrationData const*>(&ownerRegistrationData)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Unregister(void* ownerName) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Unregister(*reinterpret_cast<hstring const*>(&ownerName));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentPostMessageResult> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentPostMessageResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentPostMessageStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
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
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentProcess> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentProcess>
    {
        int32_t __stdcall get_State(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentProcessState>(this->shim().State());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExitCode(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ExitCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall WaitForExit() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WaitForExit();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall WaitForExitWithTimeout(uint32_t timeoutMilliseconds) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WaitForExitWithTimeout(timeoutMilliseconds);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall WaitForExitAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().WaitForExitAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFileRequestOptions> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFileRequestOptions>
    {
        int32_t __stdcall get_AllowWrite(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AllowWrite());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AllowWrite(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowWrite(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFileResult> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFileResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFileStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_File(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentFile>(this->shim().File());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFolderRequestOptions> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFolderRequestOptions>
    {
        int32_t __stdcall get_AllowWrite(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AllowWrite());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AllowWrite(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowWrite(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFolderResult> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFolderResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFolderStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
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
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentStartProcessResult> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentStartProcessResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentStartProcessStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Process(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentProcess>(this->shim().Process());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentTelemetryParameters> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentTelemetryParameters>
    {
        int32_t __stdcall get_CorrelationId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().CorrelationId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CorrelationId(llm::guid value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CorrelationId(*reinterpret_cast<llm::guid const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentUserInfo> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentUserInfo>
    {
        int32_t __stdcall get_EnvironmentUserSid(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().EnvironmentUserSid());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EnvironmentUserName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().EnvironmentUserName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryWaitForSignInAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().TryWaitForSignInAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentUserInfo2> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentUserInfo2>
    {
        int32_t __stdcall TryWaitForSignInWithProgressAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<bool, llm::OS::Security::Isolation::IsolatedWindowsEnvironmentSignInProgress>>(this->shim().TryWaitForSignInWithProgressAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsHostMessengerStatics> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsHostMessengerStatics>
    {
        int32_t __stdcall PostMessageToReceiver(llm::guid receiverId, void* message) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PostMessageToReceiver(*reinterpret_cast<llm::guid const*>(&receiverId), *reinterpret_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::IInspectable> const*>(&message));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFileId(void* filePath, llm::guid* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::guid>(this->shim().GetFileId(*reinterpret_cast<hstring const*>(&filePath)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Isolation::IIsolatedWindowsHostMessengerStatics2> : produce_base<D, llm::OS::Security::Isolation::IIsolatedWindowsHostMessengerStatics2>
    {
        int32_t __stdcall RegisterHostMessageReceiver(llm::guid receiverId, void* hostMessageReceivedCallback) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RegisterHostMessageReceiver(*reinterpret_cast<llm::guid const*>(&receiverId), *reinterpret_cast<llm::OS::Security::Isolation::HostMessageReceivedCallback const*>(&hostMessageReceivedCallback));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UnregisterHostMessageReceiver(llm::guid receiverId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UnregisterHostMessageReceiver(*reinterpret_cast<llm::guid const*>(&receiverId));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Security::Isolation
{
    constexpr auto operator|(IsolatedWindowsEnvironmentAllowedClipboardFormats const left, IsolatedWindowsEnvironmentAllowedClipboardFormats const right) noexcept
    {
        return static_cast<IsolatedWindowsEnvironmentAllowedClipboardFormats>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(IsolatedWindowsEnvironmentAllowedClipboardFormats& left, IsolatedWindowsEnvironmentAllowedClipboardFormats const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(IsolatedWindowsEnvironmentAllowedClipboardFormats const left, IsolatedWindowsEnvironmentAllowedClipboardFormats const right) noexcept
    {
        return static_cast<IsolatedWindowsEnvironmentAllowedClipboardFormats>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(IsolatedWindowsEnvironmentAllowedClipboardFormats& left, IsolatedWindowsEnvironmentAllowedClipboardFormats const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(IsolatedWindowsEnvironmentAllowedClipboardFormats const value) noexcept
    {
        return static_cast<IsolatedWindowsEnvironmentAllowedClipboardFormats>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(IsolatedWindowsEnvironmentAllowedClipboardFormats const left, IsolatedWindowsEnvironmentAllowedClipboardFormats const right) noexcept
    {
        return static_cast<IsolatedWindowsEnvironmentAllowedClipboardFormats>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(IsolatedWindowsEnvironmentAllowedClipboardFormats& left, IsolatedWindowsEnvironmentAllowedClipboardFormats const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    constexpr auto operator|(IsolatedWindowsEnvironmentAvailablePrinters const left, IsolatedWindowsEnvironmentAvailablePrinters const right) noexcept
    {
        return static_cast<IsolatedWindowsEnvironmentAvailablePrinters>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(IsolatedWindowsEnvironmentAvailablePrinters& left, IsolatedWindowsEnvironmentAvailablePrinters const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(IsolatedWindowsEnvironmentAvailablePrinters const left, IsolatedWindowsEnvironmentAvailablePrinters const right) noexcept
    {
        return static_cast<IsolatedWindowsEnvironmentAvailablePrinters>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(IsolatedWindowsEnvironmentAvailablePrinters& left, IsolatedWindowsEnvironmentAvailablePrinters const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(IsolatedWindowsEnvironmentAvailablePrinters const value) noexcept
    {
        return static_cast<IsolatedWindowsEnvironmentAvailablePrinters>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(IsolatedWindowsEnvironmentAvailablePrinters const left, IsolatedWindowsEnvironmentAvailablePrinters const right) noexcept
    {
        return static_cast<IsolatedWindowsEnvironmentAvailablePrinters>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(IsolatedWindowsEnvironmentAvailablePrinters& left, IsolatedWindowsEnvironmentAvailablePrinters const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    constexpr auto operator|(IsolatedWindowsEnvironmentClipboardCopyPasteDirections const left, IsolatedWindowsEnvironmentClipboardCopyPasteDirections const right) noexcept
    {
        return static_cast<IsolatedWindowsEnvironmentClipboardCopyPasteDirections>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(IsolatedWindowsEnvironmentClipboardCopyPasteDirections& left, IsolatedWindowsEnvironmentClipboardCopyPasteDirections const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(IsolatedWindowsEnvironmentClipboardCopyPasteDirections const left, IsolatedWindowsEnvironmentClipboardCopyPasteDirections const right) noexcept
    {
        return static_cast<IsolatedWindowsEnvironmentClipboardCopyPasteDirections>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(IsolatedWindowsEnvironmentClipboardCopyPasteDirections& left, IsolatedWindowsEnvironmentClipboardCopyPasteDirections const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(IsolatedWindowsEnvironmentClipboardCopyPasteDirections const value) noexcept
    {
        return static_cast<IsolatedWindowsEnvironmentClipboardCopyPasteDirections>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(IsolatedWindowsEnvironmentClipboardCopyPasteDirections const left, IsolatedWindowsEnvironmentClipboardCopyPasteDirections const right) noexcept
    {
        return static_cast<IsolatedWindowsEnvironmentClipboardCopyPasteDirections>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(IsolatedWindowsEnvironmentClipboardCopyPasteDirections& left, IsolatedWindowsEnvironmentClipboardCopyPasteDirections const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto IsolatedWindowsEnvironment::CreateAsync(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentOptions const& options)
    {
        return impl::call_factory<IsolatedWindowsEnvironment, IIsolatedWindowsEnvironmentFactory>([&](IIsolatedWindowsEnvironmentFactory const& f) { return f.CreateAsync(options); });
    }
    inline auto IsolatedWindowsEnvironment::CreateAsync(llm::OS::Security::Isolation::IsolatedWindowsEnvironmentOptions const& options, llm::OS::Security::Isolation::IsolatedWindowsEnvironmentTelemetryParameters const& telemetryParameters)
    {
        return impl::call_factory<IsolatedWindowsEnvironment, IIsolatedWindowsEnvironmentFactory>([&](IIsolatedWindowsEnvironmentFactory const& f) { return f.CreateAsync(options, telemetryParameters); });
    }
    inline auto IsolatedWindowsEnvironment::GetById(param::hstring const& environmentId)
    {
        return impl::call_factory<IsolatedWindowsEnvironment, IIsolatedWindowsEnvironmentFactory>([&](IIsolatedWindowsEnvironmentFactory const& f) { return f.GetById(environmentId); });
    }
    inline auto IsolatedWindowsEnvironment::FindByOwnerId(param::hstring const& environmentOwnerId)
    {
        return impl::call_factory<IsolatedWindowsEnvironment, IIsolatedWindowsEnvironmentFactory>([&](IIsolatedWindowsEnvironmentFactory const& f) { return f.FindByOwnerId(environmentOwnerId); });
    }
    inline auto IsolatedWindowsEnvironmentHost::IsReady()
    {
        return impl::call_factory_cast<bool(*)(IIsolatedWindowsEnvironmentHostStatics const&), IsolatedWindowsEnvironmentHost, IIsolatedWindowsEnvironmentHostStatics>([](IIsolatedWindowsEnvironmentHostStatics const& f) { return f.IsReady(); });
    }
    inline auto IsolatedWindowsEnvironmentHost::HostErrors()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentHostError>(*)(IIsolatedWindowsEnvironmentHostStatics const&), IsolatedWindowsEnvironmentHost, IIsolatedWindowsEnvironmentHostStatics>([](IIsolatedWindowsEnvironmentHostStatics const& f) { return f.HostErrors(); });
    }
    inline IsolatedWindowsEnvironmentOptions::IsolatedWindowsEnvironmentOptions() :
        IsolatedWindowsEnvironmentOptions(impl::call_factory_cast<IsolatedWindowsEnvironmentOptions(*)(llm::OS::Foundation::IActivationFactory const&), IsolatedWindowsEnvironmentOptions>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<IsolatedWindowsEnvironmentOptions>(); }))
    {
    }
    inline auto IsolatedWindowsEnvironmentOwnerRegistration::Register(param::hstring const& ownerName, llm::OS::Security::Isolation::IsolatedWindowsEnvironmentOwnerRegistrationData const& ownerRegistrationData)
    {
        return impl::call_factory<IsolatedWindowsEnvironmentOwnerRegistration, IIsolatedWindowsEnvironmentOwnerRegistrationStatics>([&](IIsolatedWindowsEnvironmentOwnerRegistrationStatics const& f) { return f.Register(ownerName, ownerRegistrationData); });
    }
    inline auto IsolatedWindowsEnvironmentOwnerRegistration::Unregister(param::hstring const& ownerName)
    {
        impl::call_factory<IsolatedWindowsEnvironmentOwnerRegistration, IIsolatedWindowsEnvironmentOwnerRegistrationStatics>([&](IIsolatedWindowsEnvironmentOwnerRegistrationStatics const& f) { return f.Unregister(ownerName); });
    }
    inline IsolatedWindowsEnvironmentOwnerRegistrationData::IsolatedWindowsEnvironmentOwnerRegistrationData() :
        IsolatedWindowsEnvironmentOwnerRegistrationData(impl::call_factory_cast<IsolatedWindowsEnvironmentOwnerRegistrationData(*)(llm::OS::Foundation::IActivationFactory const&), IsolatedWindowsEnvironmentOwnerRegistrationData>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<IsolatedWindowsEnvironmentOwnerRegistrationData>(); }))
    {
    }
    inline IsolatedWindowsEnvironmentShareFileRequestOptions::IsolatedWindowsEnvironmentShareFileRequestOptions() :
        IsolatedWindowsEnvironmentShareFileRequestOptions(impl::call_factory_cast<IsolatedWindowsEnvironmentShareFileRequestOptions(*)(llm::OS::Foundation::IActivationFactory const&), IsolatedWindowsEnvironmentShareFileRequestOptions>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<IsolatedWindowsEnvironmentShareFileRequestOptions>(); }))
    {
    }
    inline IsolatedWindowsEnvironmentShareFolderRequestOptions::IsolatedWindowsEnvironmentShareFolderRequestOptions() :
        IsolatedWindowsEnvironmentShareFolderRequestOptions(impl::call_factory_cast<IsolatedWindowsEnvironmentShareFolderRequestOptions(*)(llm::OS::Foundation::IActivationFactory const&), IsolatedWindowsEnvironmentShareFolderRequestOptions>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<IsolatedWindowsEnvironmentShareFolderRequestOptions>(); }))
    {
    }
    inline IsolatedWindowsEnvironmentTelemetryParameters::IsolatedWindowsEnvironmentTelemetryParameters() :
        IsolatedWindowsEnvironmentTelemetryParameters(impl::call_factory_cast<IsolatedWindowsEnvironmentTelemetryParameters(*)(llm::OS::Foundation::IActivationFactory const&), IsolatedWindowsEnvironmentTelemetryParameters>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<IsolatedWindowsEnvironmentTelemetryParameters>(); }))
    {
    }
    inline auto IsolatedWindowsHostMessenger::PostMessageToReceiver(llm::guid const& receiverId, param::vector_view<llm::OS::Foundation::IInspectable> const& message)
    {
        impl::call_factory<IsolatedWindowsHostMessenger, IIsolatedWindowsHostMessengerStatics>([&](IIsolatedWindowsHostMessengerStatics const& f) { return f.PostMessageToReceiver(receiverId, message); });
    }
    inline auto IsolatedWindowsHostMessenger::GetFileId(param::hstring const& filePath)
    {
        return impl::call_factory<IsolatedWindowsHostMessenger, IIsolatedWindowsHostMessengerStatics>([&](IIsolatedWindowsHostMessengerStatics const& f) { return f.GetFileId(filePath); });
    }
    inline auto IsolatedWindowsHostMessenger::RegisterHostMessageReceiver(llm::guid const& receiverId, llm::OS::Security::Isolation::HostMessageReceivedCallback const& hostMessageReceivedCallback)
    {
        impl::call_factory<IsolatedWindowsHostMessenger, IIsolatedWindowsHostMessengerStatics2>([&](IIsolatedWindowsHostMessengerStatics2 const& f) { return f.RegisterHostMessageReceiver(receiverId, hostMessageReceivedCallback); });
    }
    inline auto IsolatedWindowsHostMessenger::UnregisterHostMessageReceiver(llm::guid const& receiverId)
    {
        impl::call_factory<IsolatedWindowsHostMessenger, IIsolatedWindowsHostMessengerStatics2>([&](IIsolatedWindowsHostMessengerStatics2 const& f) { return f.UnregisterHostMessageReceiver(receiverId); });
    }
    template <typename L> HostMessageReceivedCallback::HostMessageReceivedCallback(L handler) :
        HostMessageReceivedCallback(impl::make_delegate<HostMessageReceivedCallback>(std::forward<L>(handler)))
    {
    }
    template <typename F> HostMessageReceivedCallback::HostMessageReceivedCallback(F* handler) :
        HostMessageReceivedCallback([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> HostMessageReceivedCallback::HostMessageReceivedCallback(O* object, M method) :
        HostMessageReceivedCallback([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> HostMessageReceivedCallback::HostMessageReceivedCallback(com_ptr<O>&& object, M method) :
        HostMessageReceivedCallback([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> HostMessageReceivedCallback::HostMessageReceivedCallback(weak_ref<O>&& object, M method) :
        HostMessageReceivedCallback([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto HostMessageReceivedCallback::operator()(llm::guid const& receiverId, param::vector_view<llm::OS::Foundation::IInspectable> const& message) const
    {
        check_hresult((*(impl::abi_t<HostMessageReceivedCallback>**)this)->Invoke(impl::bind_in(receiverId), *(void**)(&message)));
    }
    template <typename L> MessageReceivedCallback::MessageReceivedCallback(L handler) :
        MessageReceivedCallback(impl::make_delegate<MessageReceivedCallback>(std::forward<L>(handler)))
    {
    }
    template <typename F> MessageReceivedCallback::MessageReceivedCallback(F* handler) :
        MessageReceivedCallback([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> MessageReceivedCallback::MessageReceivedCallback(O* object, M method) :
        MessageReceivedCallback([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> MessageReceivedCallback::MessageReceivedCallback(com_ptr<O>&& object, M method) :
        MessageReceivedCallback([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> MessageReceivedCallback::MessageReceivedCallback(weak_ref<O>&& object, M method) :
        MessageReceivedCallback([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto MessageReceivedCallback::operator()(llm::guid const& receiverId, param::vector_view<llm::OS::Foundation::IInspectable> const& message) const
    {
        check_hresult((*(impl::abi_t<MessageReceivedCallback>**)this)->Invoke(impl::bind_in(receiverId), *(void**)(&message)));
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironment> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironment2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironment3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironment4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentCreateResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentCreateResult2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentFile> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentFile2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentHostStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentLaunchFileResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOwnerRegistrationData> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOwnerRegistrationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentOwnerRegistrationStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentPostMessageResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentProcess> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFileRequestOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFileResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFolderRequestOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFolderResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentStartProcessResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentTelemetryParameters> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentUserInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsEnvironmentUserInfo2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsHostMessengerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IIsolatedWindowsHostMessengerStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IsolatedWindowsEnvironment> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentCreateResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentFile> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentHost> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentLaunchFileResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentOwnerRegistration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentOwnerRegistrationData> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentOwnerRegistrationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentPostMessageResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentProcess> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFileRequestOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFileResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFolderRequestOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentShareFolderResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentStartProcessResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentTelemetryParameters> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IsolatedWindowsEnvironmentUserInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Isolation::IsolatedWindowsHostMessenger> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
