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
#ifndef LLM_OS_Networking_BackgroundTransfer_H
#define LLM_OS_Networking_BackgroundTransfer_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Networking.h"
#include "llm/impl/Windows.ApplicationModel.Background.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Security.Credentials.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.UI.Notifications.2.h"
#include "llm/impl/Windows.Web.2.h"
#include "llm/impl/Windows.Networking.BackgroundTransfer.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::BackgroundTransfer::DownloadOperation) consume_Windows_Networking_BackgroundTransfer_IBackgroundDownloader<D>::CreateDownload(llm::OS::Foundation::Uri const& uri, llm::OS::Storage::IStorageFile const& resultFile) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundDownloader)->CreateDownload(*(void**)(&uri), *(void**)(&resultFile), &operation));
        return llm::OS::Networking::BackgroundTransfer::DownloadOperation{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::BackgroundTransfer::DownloadOperation) consume_Windows_Networking_BackgroundTransfer_IBackgroundDownloader<D>::CreateDownload(llm::OS::Foundation::Uri const& uri, llm::OS::Storage::IStorageFile const& resultFile, llm::OS::Storage::IStorageFile const& requestBodyFile) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundDownloader)->CreateDownloadFromFile(*(void**)(&uri), *(void**)(&resultFile), *(void**)(&requestBodyFile), &operation));
        return llm::OS::Networking::BackgroundTransfer::DownloadOperation{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::BackgroundTransfer::DownloadOperation>) consume_Windows_Networking_BackgroundTransfer_IBackgroundDownloader<D>::CreateDownloadAsync(llm::OS::Foundation::Uri const& uri, llm::OS::Storage::IStorageFile const& resultFile, llm::OS::Storage::Streams::IInputStream const& requestBodyStream) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundDownloader)->CreateDownloadAsync(*(void**)(&uri), *(void**)(&resultFile), *(void**)(&requestBodyStream), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::BackgroundTransfer::DownloadOperation>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup) consume_Windows_Networking_BackgroundTransfer_IBackgroundDownloader2<D>::TransferGroup() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundDownloader2)->get_TransferGroup(&value));
        return llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IBackgroundDownloader2<D>::TransferGroup(llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundDownloader2)->put_TransferGroup(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Notifications::ToastNotification) consume_Windows_Networking_BackgroundTransfer_IBackgroundDownloader2<D>::SuccessToastNotification() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundDownloader2)->get_SuccessToastNotification(&value));
        return llm::OS::UI::Notifications::ToastNotification{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IBackgroundDownloader2<D>::SuccessToastNotification(llm::OS::UI::Notifications::ToastNotification const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundDownloader2)->put_SuccessToastNotification(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Notifications::ToastNotification) consume_Windows_Networking_BackgroundTransfer_IBackgroundDownloader2<D>::FailureToastNotification() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundDownloader2)->get_FailureToastNotification(&value));
        return llm::OS::UI::Notifications::ToastNotification{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IBackgroundDownloader2<D>::FailureToastNotification(llm::OS::UI::Notifications::ToastNotification const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundDownloader2)->put_FailureToastNotification(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Notifications::TileNotification) consume_Windows_Networking_BackgroundTransfer_IBackgroundDownloader2<D>::SuccessTileNotification() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundDownloader2)->get_SuccessTileNotification(&value));
        return llm::OS::UI::Notifications::TileNotification{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IBackgroundDownloader2<D>::SuccessTileNotification(llm::OS::UI::Notifications::TileNotification const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundDownloader2)->put_SuccessTileNotification(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Notifications::TileNotification) consume_Windows_Networking_BackgroundTransfer_IBackgroundDownloader2<D>::FailureTileNotification() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundDownloader2)->get_FailureTileNotification(&value));
        return llm::OS::UI::Notifications::TileNotification{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IBackgroundDownloader2<D>::FailureTileNotification(llm::OS::UI::Notifications::TileNotification const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundDownloader2)->put_FailureTileNotification(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup) consume_Windows_Networking_BackgroundTransfer_IBackgroundDownloader3<D>::CompletionGroup() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundDownloader3)->get_CompletionGroup(&value));
        return llm::OS::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::BackgroundTransfer::BackgroundDownloader) consume_Windows_Networking_BackgroundTransfer_IBackgroundDownloaderFactory<D>::CreateWithCompletionGroup(llm::OS::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup const& completionGroup) const
    {
        void* backgroundDownloader{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundDownloaderFactory)->CreateWithCompletionGroup(*(void**)(&completionGroup), &backgroundDownloader));
        return llm::OS::Networking::BackgroundTransfer::BackgroundDownloader{ backgroundDownloader, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::DownloadOperation>>) consume_Windows_Networking_BackgroundTransfer_IBackgroundDownloaderStaticMethods<D>::GetCurrentDownloadsAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundDownloaderStaticMethods)->GetCurrentDownloadsAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::DownloadOperation>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::DownloadOperation>>) consume_Windows_Networking_BackgroundTransfer_IBackgroundDownloaderStaticMethods<D>::GetCurrentDownloadsAsync(param::hstring const& group) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundDownloaderStaticMethods)->GetCurrentDownloadsForGroupAsync(*(void**)(&group), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::DownloadOperation>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::DownloadOperation>>) consume_Windows_Networking_BackgroundTransfer_IBackgroundDownloaderStaticMethods2<D>::GetCurrentDownloadsForTransferGroupAsync(llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup const& group) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundDownloaderStaticMethods2)->GetCurrentDownloadsForTransferGroupAsync(*(void**)(&group), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::DownloadOperation>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult>) consume_Windows_Networking_BackgroundTransfer_IBackgroundDownloaderUserConsent<D>::RequestUnconstrainedDownloadsAsync(param::async_iterable<llm::OS::Networking::BackgroundTransfer::DownloadOperation> const& operations) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundDownloaderUserConsent)->RequestUnconstrainedDownloadsAsync(*(void**)(&operations), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferBase<D>::SetRequestHeader(param::hstring const& headerName, param::hstring const& headerValue) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferBase)->SetRequestHeader(*(void**)(&headerName), *(void**)(&headerValue)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Credentials::PasswordCredential) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferBase<D>::ServerCredential() const
    {
        void* credential{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferBase)->get_ServerCredential(&credential));
        return llm::OS::Security::Credentials::PasswordCredential{ credential, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferBase<D>::ServerCredential(llm::OS::Security::Credentials::PasswordCredential const& credential) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferBase)->put_ServerCredential(*(void**)(&credential)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Credentials::PasswordCredential) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferBase<D>::ProxyCredential() const
    {
        void* credential{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferBase)->get_ProxyCredential(&credential));
        return llm::OS::Security::Credentials::PasswordCredential{ credential, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferBase<D>::ProxyCredential(llm::OS::Security::Credentials::PasswordCredential const& credential) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferBase)->put_ProxyCredential(*(void**)(&credential)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferBase<D>::Method() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferBase)->get_Method(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferBase<D>::Method(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferBase)->put_Method(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferBase<D>::Group() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferBase)->get_Group(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferBase<D>::Group(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferBase)->put_Group(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::BackgroundTransfer::BackgroundTransferCostPolicy) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferBase<D>::CostPolicy() const
    {
        llm::OS::Networking::BackgroundTransfer::BackgroundTransferCostPolicy value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferBase)->get_CostPolicy(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferBase<D>::CostPolicy(llm::OS::Networking::BackgroundTransfer::BackgroundTransferCostPolicy const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferBase)->put_CostPolicy(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::IBackgroundTrigger) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferCompletionGroup<D>::Trigger() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup)->get_Trigger(&value));
        return llm::OS::ApplicationModel::Background::IBackgroundTrigger{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferCompletionGroup<D>::IsEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup)->get_IsEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferCompletionGroup<D>::Enable() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup)->Enable());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::DownloadOperation>) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferCompletionGroupTriggerDetails<D>::Downloads() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroupTriggerDetails)->get_Downloads(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::DownloadOperation>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::UploadOperation>) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferCompletionGroupTriggerDetails<D>::Uploads() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroupTriggerDetails)->get_Uploads(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::UploadOperation>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferContentPart<D>::SetHeader(param::hstring const& headerName, param::hstring const& headerValue) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferContentPart)->SetHeader(*(void**)(&headerName), *(void**)(&headerValue)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferContentPart<D>::SetText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferContentPart)->SetText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferContentPart<D>::SetFile(llm::OS::Storage::IStorageFile const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferContentPart)->SetFile(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::BackgroundTransfer::BackgroundTransferContentPart) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferContentPartFactory<D>::CreateWithName(param::hstring const& name) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferContentPartFactory)->CreateWithName(*(void**)(&name), &value));
        return llm::OS::Networking::BackgroundTransfer::BackgroundTransferContentPart{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::BackgroundTransfer::BackgroundTransferContentPart) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferContentPartFactory<D>::CreateWithNameAndFileName(param::hstring const& name, param::hstring const& fileName) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferContentPartFactory)->CreateWithNameAndFileName(*(void**)(&name), *(void**)(&fileName), &value));
        return llm::OS::Networking::BackgroundTransfer::BackgroundTransferContentPart{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::WebErrorStatus) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferErrorStaticMethods<D>::GetStatus(int32_t hresult) const
    {
        llm::OS::Web::WebErrorStatus status{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferErrorStaticMethods)->GetStatus(hresult, reinterpret_cast<int32_t*>(&status)));
        return status;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferGroup<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferGroup)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::BackgroundTransfer::BackgroundTransferBehavior) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferGroup<D>::TransferBehavior() const
    {
        llm::OS::Networking::BackgroundTransfer::BackgroundTransferBehavior value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferGroup)->get_TransferBehavior(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferGroup<D>::TransferBehavior(llm::OS::Networking::BackgroundTransfer::BackgroundTransferBehavior const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferGroup)->put_TransferBehavior(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferGroupStatics<D>::CreateGroup(param::hstring const& name) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferGroupStatics)->CreateGroup(*(void**)(&name), &value));
        return llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferOperation<D>::Guid() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferOperation)->get_Guid(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferOperation<D>::RequestedUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferOperation)->get_RequestedUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferOperation<D>::Method() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferOperation)->get_Method(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferOperation<D>::Group() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferOperation)->get_Group(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::BackgroundTransfer::BackgroundTransferCostPolicy) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferOperation<D>::CostPolicy() const
    {
        llm::OS::Networking::BackgroundTransfer::BackgroundTransferCostPolicy value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferOperation)->get_CostPolicy(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferOperation<D>::CostPolicy(llm::OS::Networking::BackgroundTransfer::BackgroundTransferCostPolicy const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferOperation)->put_CostPolicy(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IInputStream) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferOperation<D>::GetResultStreamAt(uint64_t position) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferOperation)->GetResultStreamAt(position, &value));
        return llm::OS::Storage::Streams::IInputStream{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::BackgroundTransfer::ResponseInformation) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferOperation<D>::GetResponseInformation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferOperation)->GetResponseInformation(&value));
        return llm::OS::Networking::BackgroundTransfer::ResponseInformation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::BackgroundTransfer::BackgroundTransferPriority) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferOperationPriority<D>::Priority() const
    {
        llm::OS::Networking::BackgroundTransfer::BackgroundTransferPriority value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferOperationPriority)->get_Priority(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferOperationPriority<D>::Priority(llm::OS::Networking::BackgroundTransfer::BackgroundTransferPriority const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferOperationPriority)->put_Priority(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferRangesDownloadedEventArgs<D>::WasDownloadRestarted() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferRangesDownloadedEventArgs)->get_WasDownloadRestarted(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Networking::BackgroundTransfer::BackgroundTransferFileRange>) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferRangesDownloadedEventArgs<D>::AddedRanges() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferRangesDownloadedEventArgs)->get_AddedRanges(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Networking::BackgroundTransfer::BackgroundTransferFileRange>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_Networking_BackgroundTransfer_IBackgroundTransferRangesDownloadedEventArgs<D>::GetDeferral() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundTransferRangesDownloadedEventArgs)->GetDeferral(&result));
        return llm::OS::Foundation::Deferral{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::BackgroundTransfer::UploadOperation) consume_Windows_Networking_BackgroundTransfer_IBackgroundUploader<D>::CreateUpload(llm::OS::Foundation::Uri const& uri, llm::OS::Storage::IStorageFile const& sourceFile) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundUploader)->CreateUpload(*(void**)(&uri), *(void**)(&sourceFile), &operation));
        return llm::OS::Networking::BackgroundTransfer::UploadOperation{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::BackgroundTransfer::UploadOperation>) consume_Windows_Networking_BackgroundTransfer_IBackgroundUploader<D>::CreateUploadFromStreamAsync(llm::OS::Foundation::Uri const& uri, llm::OS::Storage::Streams::IInputStream const& sourceStream) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundUploader)->CreateUploadFromStreamAsync(*(void**)(&uri), *(void**)(&sourceStream), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::BackgroundTransfer::UploadOperation>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::BackgroundTransfer::UploadOperation>) consume_Windows_Networking_BackgroundTransfer_IBackgroundUploader<D>::CreateUploadAsync(llm::OS::Foundation::Uri const& uri, param::async_iterable<llm::OS::Networking::BackgroundTransfer::BackgroundTransferContentPart> const& parts) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundUploader)->CreateUploadWithFormDataAndAutoBoundaryAsync(*(void**)(&uri), *(void**)(&parts), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::BackgroundTransfer::UploadOperation>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::BackgroundTransfer::UploadOperation>) consume_Windows_Networking_BackgroundTransfer_IBackgroundUploader<D>::CreateUploadAsync(llm::OS::Foundation::Uri const& uri, param::async_iterable<llm::OS::Networking::BackgroundTransfer::BackgroundTransferContentPart> const& parts, param::hstring const& subType) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundUploader)->CreateUploadWithSubTypeAsync(*(void**)(&uri), *(void**)(&parts), *(void**)(&subType), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::BackgroundTransfer::UploadOperation>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::BackgroundTransfer::UploadOperation>) consume_Windows_Networking_BackgroundTransfer_IBackgroundUploader<D>::CreateUploadAsync(llm::OS::Foundation::Uri const& uri, param::async_iterable<llm::OS::Networking::BackgroundTransfer::BackgroundTransferContentPart> const& parts, param::hstring const& subType, param::hstring const& boundary) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundUploader)->CreateUploadWithSubTypeAndBoundaryAsync(*(void**)(&uri), *(void**)(&parts), *(void**)(&subType), *(void**)(&boundary), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::BackgroundTransfer::UploadOperation>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup) consume_Windows_Networking_BackgroundTransfer_IBackgroundUploader2<D>::TransferGroup() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundUploader2)->get_TransferGroup(&value));
        return llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IBackgroundUploader2<D>::TransferGroup(llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundUploader2)->put_TransferGroup(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Notifications::ToastNotification) consume_Windows_Networking_BackgroundTransfer_IBackgroundUploader2<D>::SuccessToastNotification() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundUploader2)->get_SuccessToastNotification(&value));
        return llm::OS::UI::Notifications::ToastNotification{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IBackgroundUploader2<D>::SuccessToastNotification(llm::OS::UI::Notifications::ToastNotification const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundUploader2)->put_SuccessToastNotification(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Notifications::ToastNotification) consume_Windows_Networking_BackgroundTransfer_IBackgroundUploader2<D>::FailureToastNotification() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundUploader2)->get_FailureToastNotification(&value));
        return llm::OS::UI::Notifications::ToastNotification{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IBackgroundUploader2<D>::FailureToastNotification(llm::OS::UI::Notifications::ToastNotification const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundUploader2)->put_FailureToastNotification(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Notifications::TileNotification) consume_Windows_Networking_BackgroundTransfer_IBackgroundUploader2<D>::SuccessTileNotification() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundUploader2)->get_SuccessTileNotification(&value));
        return llm::OS::UI::Notifications::TileNotification{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IBackgroundUploader2<D>::SuccessTileNotification(llm::OS::UI::Notifications::TileNotification const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundUploader2)->put_SuccessTileNotification(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Notifications::TileNotification) consume_Windows_Networking_BackgroundTransfer_IBackgroundUploader2<D>::FailureTileNotification() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundUploader2)->get_FailureTileNotification(&value));
        return llm::OS::UI::Notifications::TileNotification{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IBackgroundUploader2<D>::FailureTileNotification(llm::OS::UI::Notifications::TileNotification const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundUploader2)->put_FailureTileNotification(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup) consume_Windows_Networking_BackgroundTransfer_IBackgroundUploader3<D>::CompletionGroup() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundUploader3)->get_CompletionGroup(&value));
        return llm::OS::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::BackgroundTransfer::BackgroundUploader) consume_Windows_Networking_BackgroundTransfer_IBackgroundUploaderFactory<D>::CreateWithCompletionGroup(llm::OS::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup const& completionGroup) const
    {
        void* backgroundUploader{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundUploaderFactory)->CreateWithCompletionGroup(*(void**)(&completionGroup), &backgroundUploader));
        return llm::OS::Networking::BackgroundTransfer::BackgroundUploader{ backgroundUploader, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::UploadOperation>>) consume_Windows_Networking_BackgroundTransfer_IBackgroundUploaderStaticMethods<D>::GetCurrentUploadsAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundUploaderStaticMethods)->GetCurrentUploadsAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::UploadOperation>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::UploadOperation>>) consume_Windows_Networking_BackgroundTransfer_IBackgroundUploaderStaticMethods<D>::GetCurrentUploadsAsync(param::hstring const& group) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundUploaderStaticMethods)->GetCurrentUploadsForGroupAsync(*(void**)(&group), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::UploadOperation>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::UploadOperation>>) consume_Windows_Networking_BackgroundTransfer_IBackgroundUploaderStaticMethods2<D>::GetCurrentUploadsForTransferGroupAsync(llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup const& group) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundUploaderStaticMethods2)->GetCurrentUploadsForTransferGroupAsync(*(void**)(&group), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::UploadOperation>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult>) consume_Windows_Networking_BackgroundTransfer_IBackgroundUploaderUserConsent<D>::RequestUnconstrainedUploadsAsync(param::async_iterable<llm::OS::Networking::BackgroundTransfer::UploadOperation> const& operations) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IBackgroundUploaderUserConsent)->RequestUnconstrainedUploadsAsync(*(void**)(&operations), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Foundation::Uri>) consume_Windows_Networking_BackgroundTransfer_IContentPrefetcher<D>::ContentUris() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IContentPrefetcher)->get_ContentUris(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Foundation::Uri>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IContentPrefetcher<D>::IndirectContentUri(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IContentPrefetcher)->put_IndirectContentUri(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Networking_BackgroundTransfer_IContentPrefetcher<D>::IndirectContentUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IContentPrefetcher)->get_IndirectContentUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) consume_Windows_Networking_BackgroundTransfer_IContentPrefetcherTime<D>::LastSuccessfulPrefetchTime() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IContentPrefetcherTime)->get_LastSuccessfulPrefetchTime(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::IStorageFile) consume_Windows_Networking_BackgroundTransfer_IDownloadOperation<D>::ResultFile() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IDownloadOperation)->get_ResultFile(&value));
        return llm::OS::Storage::IStorageFile{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::BackgroundTransfer::BackgroundDownloadProgress) consume_Windows_Networking_BackgroundTransfer_IDownloadOperation<D>::Progress() const
    {
        llm::OS::Networking::BackgroundTransfer::BackgroundDownloadProgress value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IDownloadOperation)->get_Progress(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Networking::BackgroundTransfer::DownloadOperation, llm::OS::Networking::BackgroundTransfer::DownloadOperation>) consume_Windows_Networking_BackgroundTransfer_IDownloadOperation<D>::StartAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IDownloadOperation)->StartAsync(&operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Networking::BackgroundTransfer::DownloadOperation, llm::OS::Networking::BackgroundTransfer::DownloadOperation>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Networking::BackgroundTransfer::DownloadOperation, llm::OS::Networking::BackgroundTransfer::DownloadOperation>) consume_Windows_Networking_BackgroundTransfer_IDownloadOperation<D>::AttachAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IDownloadOperation)->AttachAsync(&operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Networking::BackgroundTransfer::DownloadOperation, llm::OS::Networking::BackgroundTransfer::DownloadOperation>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IDownloadOperation<D>::Pause() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IDownloadOperation)->Pause());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IDownloadOperation<D>::Resume() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IDownloadOperation)->Resume());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup) consume_Windows_Networking_BackgroundTransfer_IDownloadOperation2<D>::TransferGroup() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IDownloadOperation2)->get_TransferGroup(&value));
        return llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_BackgroundTransfer_IDownloadOperation3<D>::IsRandomAccessRequired() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IDownloadOperation3)->get_IsRandomAccessRequired(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IDownloadOperation3<D>::IsRandomAccessRequired(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IDownloadOperation3)->put_IsRandomAccessRequired(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamReference) consume_Windows_Networking_BackgroundTransfer_IDownloadOperation3<D>::GetResultRandomAccessStreamReference() const
    {
        void* stream{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IDownloadOperation3)->GetResultRandomAccessStreamReference(&stream));
        return llm::OS::Storage::Streams::IRandomAccessStreamReference{ stream, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Networking::BackgroundTransfer::BackgroundTransferFileRange>) consume_Windows_Networking_BackgroundTransfer_IDownloadOperation3<D>::GetDownloadedRanges() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IDownloadOperation3)->GetDownloadedRanges(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Networking::BackgroundTransfer::BackgroundTransferFileRange>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Networking_BackgroundTransfer_IDownloadOperation3<D>::RangesDownloaded(llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::BackgroundTransfer::DownloadOperation, llm::OS::Networking::BackgroundTransfer::BackgroundTransferRangesDownloadedEventArgs> const& eventHandler) const
    {
        llm::event_token eventCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IDownloadOperation3)->add_RangesDownloaded(*(void**)(&eventHandler), put_abi(eventCookie)));
        return eventCookie;
    }
    template <typename D> typename consume_Windows_Networking_BackgroundTransfer_IDownloadOperation3<D>::RangesDownloaded_revoker consume_Windows_Networking_BackgroundTransfer_IDownloadOperation3<D>::RangesDownloaded(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::BackgroundTransfer::DownloadOperation, llm::OS::Networking::BackgroundTransfer::BackgroundTransferRangesDownloadedEventArgs> const& eventHandler) const
    {
        return impl::make_event_revoker<D, RangesDownloaded_revoker>(this, RangesDownloaded(eventHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IDownloadOperation3<D>::RangesDownloaded(llm::event_token const& eventCookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IDownloadOperation3)->remove_RangesDownloaded(impl::bind_in(eventCookie));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IDownloadOperation3<D>::RequestedUri(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IDownloadOperation3)->put_RequestedUri(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Web::WebErrorStatus>) consume_Windows_Networking_BackgroundTransfer_IDownloadOperation3<D>::RecoverableWebErrorStatuses() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IDownloadOperation3)->get_RecoverableWebErrorStatuses(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Web::WebErrorStatus>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Web::WebErrorStatus>) consume_Windows_Networking_BackgroundTransfer_IDownloadOperation3<D>::CurrentWebErrorStatus() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IDownloadOperation3)->get_CurrentWebErrorStatus(&value));
        return llm::OS::Foundation::IReference<llm::OS::Web::WebErrorStatus>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IDownloadOperation4<D>::MakeCurrentInTransferGroup() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IDownloadOperation4)->MakeCurrentInTransferGroup());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IDownloadOperation5<D>::SetRequestHeader(param::hstring const& headerName, param::hstring const& headerValue) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IDownloadOperation5)->SetRequestHeader(*(void**)(&headerName), *(void**)(&headerValue)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IDownloadOperation5<D>::RemoveRequestHeader(param::hstring const& headerName) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IDownloadOperation5)->RemoveRequestHeader(*(void**)(&headerName)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_BackgroundTransfer_IResponseInformation<D>::IsResumable() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IResponseInformation)->get_IsResumable(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Networking_BackgroundTransfer_IResponseInformation<D>::ActualUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IResponseInformation)->get_ActualUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_BackgroundTransfer_IResponseInformation<D>::StatusCode() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IResponseInformation)->get_StatusCode(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, hstring>) consume_Windows_Networking_BackgroundTransfer_IResponseInformation<D>::Headers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IResponseInformation)->get_Headers(&value));
        return llm::OS::Foundation::Collections::IMapView<hstring, hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_BackgroundTransfer_IUnconstrainedTransferRequestResult<D>::IsUnconstrained() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IUnconstrainedTransferRequestResult)->get_IsUnconstrained(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::IStorageFile) consume_Windows_Networking_BackgroundTransfer_IUploadOperation<D>::SourceFile() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IUploadOperation)->get_SourceFile(&value));
        return llm::OS::Storage::IStorageFile{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::BackgroundTransfer::BackgroundUploadProgress) consume_Windows_Networking_BackgroundTransfer_IUploadOperation<D>::Progress() const
    {
        llm::OS::Networking::BackgroundTransfer::BackgroundUploadProgress value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IUploadOperation)->get_Progress(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Networking::BackgroundTransfer::UploadOperation, llm::OS::Networking::BackgroundTransfer::UploadOperation>) consume_Windows_Networking_BackgroundTransfer_IUploadOperation<D>::StartAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IUploadOperation)->StartAsync(&operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Networking::BackgroundTransfer::UploadOperation, llm::OS::Networking::BackgroundTransfer::UploadOperation>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Networking::BackgroundTransfer::UploadOperation, llm::OS::Networking::BackgroundTransfer::UploadOperation>) consume_Windows_Networking_BackgroundTransfer_IUploadOperation<D>::AttachAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IUploadOperation)->AttachAsync(&operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Networking::BackgroundTransfer::UploadOperation, llm::OS::Networking::BackgroundTransfer::UploadOperation>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup) consume_Windows_Networking_BackgroundTransfer_IUploadOperation2<D>::TransferGroup() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IUploadOperation2)->get_TransferGroup(&value));
        return llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IUploadOperation3<D>::MakeCurrentInTransferGroup() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IUploadOperation3)->MakeCurrentInTransferGroup());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IUploadOperation4<D>::SetRequestHeader(param::hstring const& headerName, param::hstring const& headerValue) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IUploadOperation4)->SetRequestHeader(*(void**)(&headerName), *(void**)(&headerValue)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_BackgroundTransfer_IUploadOperation4<D>::RemoveRequestHeader(param::hstring const& headerName) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::BackgroundTransfer::IUploadOperation4)->RemoveRequestHeader(*(void**)(&headerName)));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundDownloader> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundDownloader>
    {
        int32_t __stdcall CreateDownload(void* uri, void* resultFile, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Networking::BackgroundTransfer::DownloadOperation>(this->shim().CreateDownload(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&resultFile)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateDownloadFromFile(void* uri, void* resultFile, void* requestBodyFile, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Networking::BackgroundTransfer::DownloadOperation>(this->shim().CreateDownload(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&resultFile), *reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&requestBodyFile)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateDownloadAsync(void* uri, void* resultFile, void* requestBodyStream, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::BackgroundTransfer::DownloadOperation>>(this->shim().CreateDownloadAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&resultFile), *reinterpret_cast<llm::OS::Storage::Streams::IInputStream const*>(&requestBodyStream)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundDownloader2> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundDownloader2>
    {
        int32_t __stdcall get_TransferGroup(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup>(this->shim().TransferGroup());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TransferGroup(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransferGroup(*reinterpret_cast<llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SuccessToastNotification(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Notifications::ToastNotification>(this->shim().SuccessToastNotification());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SuccessToastNotification(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuccessToastNotification(*reinterpret_cast<llm::OS::UI::Notifications::ToastNotification const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FailureToastNotification(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Notifications::ToastNotification>(this->shim().FailureToastNotification());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_FailureToastNotification(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FailureToastNotification(*reinterpret_cast<llm::OS::UI::Notifications::ToastNotification const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SuccessTileNotification(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Notifications::TileNotification>(this->shim().SuccessTileNotification());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SuccessTileNotification(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuccessTileNotification(*reinterpret_cast<llm::OS::UI::Notifications::TileNotification const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FailureTileNotification(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Notifications::TileNotification>(this->shim().FailureTileNotification());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_FailureTileNotification(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FailureTileNotification(*reinterpret_cast<llm::OS::UI::Notifications::TileNotification const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundDownloader3> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundDownloader3>
    {
        int32_t __stdcall get_CompletionGroup(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup>(this->shim().CompletionGroup());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundDownloaderFactory> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundDownloaderFactory>
    {
        int32_t __stdcall CreateWithCompletionGroup(void* completionGroup, void** backgroundDownloader) noexcept final try
        {
            clear_abi(backgroundDownloader);
            typename D::abi_guard guard(this->shim());
            *backgroundDownloader = detach_from<llm::OS::Networking::BackgroundTransfer::BackgroundDownloader>(this->shim().CreateWithCompletionGroup(*reinterpret_cast<llm::OS::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup const*>(&completionGroup)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundDownloaderStaticMethods> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundDownloaderStaticMethods>
    {
        int32_t __stdcall GetCurrentDownloadsAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::DownloadOperation>>>(this->shim().GetCurrentDownloadsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetCurrentDownloadsForGroupAsync(void* group, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::DownloadOperation>>>(this->shim().GetCurrentDownloadsAsync(*reinterpret_cast<hstring const*>(&group)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundDownloaderStaticMethods2> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundDownloaderStaticMethods2>
    {
        int32_t __stdcall GetCurrentDownloadsForTransferGroupAsync(void* group, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::DownloadOperation>>>(this->shim().GetCurrentDownloadsForTransferGroupAsync(*reinterpret_cast<llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup const*>(&group)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundDownloaderUserConsent> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundDownloaderUserConsent>
    {
        int32_t __stdcall RequestUnconstrainedDownloadsAsync(void* operations, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult>>(this->shim().RequestUnconstrainedDownloadsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Networking::BackgroundTransfer::DownloadOperation> const*>(&operations)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundTransferBase> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundTransferBase>
    {
        int32_t __stdcall SetRequestHeader(void* headerName, void* headerValue) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetRequestHeader(*reinterpret_cast<hstring const*>(&headerName), *reinterpret_cast<hstring const*>(&headerValue));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ServerCredential(void** credential) noexcept final try
        {
            clear_abi(credential);
            typename D::abi_guard guard(this->shim());
            *credential = detach_from<llm::OS::Security::Credentials::PasswordCredential>(this->shim().ServerCredential());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ServerCredential(void* credential) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ServerCredential(*reinterpret_cast<llm::OS::Security::Credentials::PasswordCredential const*>(&credential));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProxyCredential(void** credential) noexcept final try
        {
            clear_abi(credential);
            typename D::abi_guard guard(this->shim());
            *credential = detach_from<llm::OS::Security::Credentials::PasswordCredential>(this->shim().ProxyCredential());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ProxyCredential(void* credential) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProxyCredential(*reinterpret_cast<llm::OS::Security::Credentials::PasswordCredential const*>(&credential));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Method(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Method());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Method(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Method(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Group(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Group());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Group(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Group(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CostPolicy(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::BackgroundTransfer::BackgroundTransferCostPolicy>(this->shim().CostPolicy());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CostPolicy(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CostPolicy(*reinterpret_cast<llm::OS::Networking::BackgroundTransfer::BackgroundTransferCostPolicy const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup>
    {
        int32_t __stdcall get_Trigger(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Background::IBackgroundTrigger>(this->shim().Trigger());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Enable() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Enable();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroupTriggerDetails> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroupTriggerDetails>
    {
        int32_t __stdcall get_Downloads(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::DownloadOperation>>(this->shim().Downloads());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Uploads(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::UploadOperation>>(this->shim().Uploads());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundTransferContentPart> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundTransferContentPart>
    {
        int32_t __stdcall SetHeader(void* headerName, void* headerValue) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetHeader(*reinterpret_cast<hstring const*>(&headerName), *reinterpret_cast<hstring const*>(&headerValue));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetFile(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetFile(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundTransferContentPartFactory> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundTransferContentPartFactory>
    {
        int32_t __stdcall CreateWithName(void* name, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::BackgroundTransfer::BackgroundTransferContentPart>(this->shim().CreateWithName(*reinterpret_cast<hstring const*>(&name)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithNameAndFileName(void* name, void* fileName, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::BackgroundTransfer::BackgroundTransferContentPart>(this->shim().CreateWithNameAndFileName(*reinterpret_cast<hstring const*>(&name), *reinterpret_cast<hstring const*>(&fileName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundTransferErrorStaticMethods> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundTransferErrorStaticMethods>
    {
        int32_t __stdcall GetStatus(int32_t hresult, int32_t* status) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_from<llm::OS::Web::WebErrorStatus>(this->shim().GetStatus(hresult));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundTransferGroup> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundTransferGroup>
    {
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TransferBehavior(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::BackgroundTransfer::BackgroundTransferBehavior>(this->shim().TransferBehavior());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TransferBehavior(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransferBehavior(*reinterpret_cast<llm::OS::Networking::BackgroundTransfer::BackgroundTransferBehavior const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundTransferGroupStatics> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundTransferGroupStatics>
    {
        int32_t __stdcall CreateGroup(void* name, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup>(this->shim().CreateGroup(*reinterpret_cast<hstring const*>(&name)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundTransferOperation> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundTransferOperation>
    {
        int32_t __stdcall get_Guid(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().Guid());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RequestedUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().RequestedUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Method(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Method());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Group(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Group());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CostPolicy(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::BackgroundTransfer::BackgroundTransferCostPolicy>(this->shim().CostPolicy());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CostPolicy(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CostPolicy(*reinterpret_cast<llm::OS::Networking::BackgroundTransfer::BackgroundTransferCostPolicy const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetResultStreamAt(uint64_t position, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IInputStream>(this->shim().GetResultStreamAt(position));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetResponseInformation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::BackgroundTransfer::ResponseInformation>(this->shim().GetResponseInformation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundTransferOperationPriority> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundTransferOperationPriority>
    {
        int32_t __stdcall get_Priority(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::BackgroundTransfer::BackgroundTransferPriority>(this->shim().Priority());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Priority(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Priority(*reinterpret_cast<llm::OS::Networking::BackgroundTransfer::BackgroundTransferPriority const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundTransferRangesDownloadedEventArgs> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundTransferRangesDownloadedEventArgs>
    {
        int32_t __stdcall get_WasDownloadRestarted(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().WasDownloadRestarted());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AddedRanges(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::BackgroundTransfer::BackgroundTransferFileRange>>(this->shim().AddedRanges());
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
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundUploader> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundUploader>
    {
        int32_t __stdcall CreateUpload(void* uri, void* sourceFile, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Networking::BackgroundTransfer::UploadOperation>(this->shim().CreateUpload(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&sourceFile)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateUploadFromStreamAsync(void* uri, void* sourceStream, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::BackgroundTransfer::UploadOperation>>(this->shim().CreateUploadFromStreamAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::Storage::Streams::IInputStream const*>(&sourceStream)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateUploadWithFormDataAndAutoBoundaryAsync(void* uri, void* parts, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::BackgroundTransfer::UploadOperation>>(this->shim().CreateUploadAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Networking::BackgroundTransfer::BackgroundTransferContentPart> const*>(&parts)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateUploadWithSubTypeAsync(void* uri, void* parts, void* subType, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::BackgroundTransfer::UploadOperation>>(this->shim().CreateUploadAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Networking::BackgroundTransfer::BackgroundTransferContentPart> const*>(&parts), *reinterpret_cast<hstring const*>(&subType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateUploadWithSubTypeAndBoundaryAsync(void* uri, void* parts, void* subType, void* boundary, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::BackgroundTransfer::UploadOperation>>(this->shim().CreateUploadAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Networking::BackgroundTransfer::BackgroundTransferContentPart> const*>(&parts), *reinterpret_cast<hstring const*>(&subType), *reinterpret_cast<hstring const*>(&boundary)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundUploader2> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundUploader2>
    {
        int32_t __stdcall get_TransferGroup(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup>(this->shim().TransferGroup());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TransferGroup(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransferGroup(*reinterpret_cast<llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SuccessToastNotification(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Notifications::ToastNotification>(this->shim().SuccessToastNotification());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SuccessToastNotification(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuccessToastNotification(*reinterpret_cast<llm::OS::UI::Notifications::ToastNotification const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FailureToastNotification(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Notifications::ToastNotification>(this->shim().FailureToastNotification());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_FailureToastNotification(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FailureToastNotification(*reinterpret_cast<llm::OS::UI::Notifications::ToastNotification const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SuccessTileNotification(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Notifications::TileNotification>(this->shim().SuccessTileNotification());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SuccessTileNotification(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuccessTileNotification(*reinterpret_cast<llm::OS::UI::Notifications::TileNotification const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FailureTileNotification(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Notifications::TileNotification>(this->shim().FailureTileNotification());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_FailureTileNotification(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FailureTileNotification(*reinterpret_cast<llm::OS::UI::Notifications::TileNotification const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundUploader3> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundUploader3>
    {
        int32_t __stdcall get_CompletionGroup(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup>(this->shim().CompletionGroup());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundUploaderFactory> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundUploaderFactory>
    {
        int32_t __stdcall CreateWithCompletionGroup(void* completionGroup, void** backgroundUploader) noexcept final try
        {
            clear_abi(backgroundUploader);
            typename D::abi_guard guard(this->shim());
            *backgroundUploader = detach_from<llm::OS::Networking::BackgroundTransfer::BackgroundUploader>(this->shim().CreateWithCompletionGroup(*reinterpret_cast<llm::OS::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup const*>(&completionGroup)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundUploaderStaticMethods> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundUploaderStaticMethods>
    {
        int32_t __stdcall GetCurrentUploadsAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::UploadOperation>>>(this->shim().GetCurrentUploadsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetCurrentUploadsForGroupAsync(void* group, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::UploadOperation>>>(this->shim().GetCurrentUploadsAsync(*reinterpret_cast<hstring const*>(&group)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundUploaderStaticMethods2> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundUploaderStaticMethods2>
    {
        int32_t __stdcall GetCurrentUploadsForTransferGroupAsync(void* group, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::UploadOperation>>>(this->shim().GetCurrentUploadsForTransferGroupAsync(*reinterpret_cast<llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup const*>(&group)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IBackgroundUploaderUserConsent> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IBackgroundUploaderUserConsent>
    {
        int32_t __stdcall RequestUnconstrainedUploadsAsync(void* operations, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult>>(this->shim().RequestUnconstrainedUploadsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Networking::BackgroundTransfer::UploadOperation> const*>(&operations)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IContentPrefetcher> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IContentPrefetcher>
    {
        int32_t __stdcall get_ContentUris(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Foundation::Uri>>(this->shim().ContentUris());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IndirectContentUri(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IndirectContentUri(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IndirectContentUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().IndirectContentUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IContentPrefetcherTime> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IContentPrefetcherTime>
    {
        int32_t __stdcall get_LastSuccessfulPrefetchTime(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>>(this->shim().LastSuccessfulPrefetchTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IDownloadOperation> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IDownloadOperation>
    {
        int32_t __stdcall get_ResultFile(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::IStorageFile>(this->shim().ResultFile());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Progress(struct struct_Windows_Networking_BackgroundTransfer_BackgroundDownloadProgress* value) noexcept final try
        {
            zero_abi<llm::OS::Networking::BackgroundTransfer::BackgroundDownloadProgress>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::BackgroundTransfer::BackgroundDownloadProgress>(this->shim().Progress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Networking::BackgroundTransfer::DownloadOperation, llm::OS::Networking::BackgroundTransfer::DownloadOperation>>(this->shim().StartAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AttachAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Networking::BackgroundTransfer::DownloadOperation, llm::OS::Networking::BackgroundTransfer::DownloadOperation>>(this->shim().AttachAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Pause() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Pause();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Resume() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Resume();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IDownloadOperation2> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IDownloadOperation2>
    {
        int32_t __stdcall get_TransferGroup(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup>(this->shim().TransferGroup());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IDownloadOperation3> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IDownloadOperation3>
    {
        int32_t __stdcall get_IsRandomAccessRequired(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsRandomAccessRequired());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsRandomAccessRequired(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsRandomAccessRequired(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetResultRandomAccessStreamReference(void** stream) noexcept final try
        {
            clear_abi(stream);
            typename D::abi_guard guard(this->shim());
            *stream = detach_from<llm::OS::Storage::Streams::IRandomAccessStreamReference>(this->shim().GetResultRandomAccessStreamReference());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDownloadedRanges(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::BackgroundTransfer::BackgroundTransferFileRange>>(this->shim().GetDownloadedRanges());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_RangesDownloaded(void* eventHandler, llm::event_token* eventCookie) noexcept final try
        {
            zero_abi<llm::event_token>(eventCookie);
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_from<llm::event_token>(this->shim().RangesDownloaded(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::BackgroundTransfer::DownloadOperation, llm::OS::Networking::BackgroundTransfer::BackgroundTransferRangesDownloadedEventArgs> const*>(&eventHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_RangesDownloaded(llm::event_token eventCookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RangesDownloaded(*reinterpret_cast<llm::event_token const*>(&eventCookie));
            return 0;
        }
        int32_t __stdcall put_RequestedUri(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestedUri(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RecoverableWebErrorStatuses(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Web::WebErrorStatus>>(this->shim().RecoverableWebErrorStatuses());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CurrentWebErrorStatus(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Web::WebErrorStatus>>(this->shim().CurrentWebErrorStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IDownloadOperation4> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IDownloadOperation4>
    {
        int32_t __stdcall MakeCurrentInTransferGroup() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MakeCurrentInTransferGroup();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IDownloadOperation5> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IDownloadOperation5>
    {
        int32_t __stdcall SetRequestHeader(void* headerName, void* headerValue) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetRequestHeader(*reinterpret_cast<hstring const*>(&headerName), *reinterpret_cast<hstring const*>(&headerValue));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveRequestHeader(void* headerName) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveRequestHeader(*reinterpret_cast<hstring const*>(&headerName));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IResponseInformation> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IResponseInformation>
    {
        int32_t __stdcall get_IsResumable(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsResumable());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ActualUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().ActualUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StatusCode(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().StatusCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Headers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<hstring, hstring>>(this->shim().Headers());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IUnconstrainedTransferRequestResult> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IUnconstrainedTransferRequestResult>
    {
        int32_t __stdcall get_IsUnconstrained(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsUnconstrained());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IUploadOperation> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IUploadOperation>
    {
        int32_t __stdcall get_SourceFile(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::IStorageFile>(this->shim().SourceFile());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Progress(struct struct_Windows_Networking_BackgroundTransfer_BackgroundUploadProgress* value) noexcept final try
        {
            zero_abi<llm::OS::Networking::BackgroundTransfer::BackgroundUploadProgress>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::BackgroundTransfer::BackgroundUploadProgress>(this->shim().Progress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Networking::BackgroundTransfer::UploadOperation, llm::OS::Networking::BackgroundTransfer::UploadOperation>>(this->shim().StartAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AttachAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Networking::BackgroundTransfer::UploadOperation, llm::OS::Networking::BackgroundTransfer::UploadOperation>>(this->shim().AttachAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IUploadOperation2> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IUploadOperation2>
    {
        int32_t __stdcall get_TransferGroup(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup>(this->shim().TransferGroup());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IUploadOperation3> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IUploadOperation3>
    {
        int32_t __stdcall MakeCurrentInTransferGroup() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MakeCurrentInTransferGroup();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::BackgroundTransfer::IUploadOperation4> : produce_base<D, llm::OS::Networking::BackgroundTransfer::IUploadOperation4>
    {
        int32_t __stdcall SetRequestHeader(void* headerName, void* headerValue) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetRequestHeader(*reinterpret_cast<hstring const*>(&headerName), *reinterpret_cast<hstring const*>(&headerValue));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveRequestHeader(void* headerName) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveRequestHeader(*reinterpret_cast<hstring const*>(&headerName));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Networking::BackgroundTransfer
{
    inline BackgroundDownloader::BackgroundDownloader() :
        BackgroundDownloader(impl::call_factory_cast<BackgroundDownloader(*)(llm::OS::Foundation::IActivationFactory const&), BackgroundDownloader>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<BackgroundDownloader>(); }))
    {
    }
    inline BackgroundDownloader::BackgroundDownloader(llm::OS::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup const& completionGroup) :
        BackgroundDownloader(impl::call_factory<BackgroundDownloader, IBackgroundDownloaderFactory>([&](IBackgroundDownloaderFactory const& f) { return f.CreateWithCompletionGroup(completionGroup); }))
    {
    }
    inline auto BackgroundDownloader::GetCurrentDownloadsAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::DownloadOperation>>(*)(IBackgroundDownloaderStaticMethods const&), BackgroundDownloader, IBackgroundDownloaderStaticMethods>([](IBackgroundDownloaderStaticMethods const& f) { return f.GetCurrentDownloadsAsync(); });
    }
    inline auto BackgroundDownloader::GetCurrentDownloadsAsync(param::hstring const& group)
    {
        return impl::call_factory<BackgroundDownloader, IBackgroundDownloaderStaticMethods>([&](IBackgroundDownloaderStaticMethods const& f) { return f.GetCurrentDownloadsAsync(group); });
    }
    inline auto BackgroundDownloader::GetCurrentDownloadsForTransferGroupAsync(llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup const& group)
    {
        return impl::call_factory<BackgroundDownloader, IBackgroundDownloaderStaticMethods2>([&](IBackgroundDownloaderStaticMethods2 const& f) { return f.GetCurrentDownloadsForTransferGroupAsync(group); });
    }
    inline auto BackgroundDownloader::RequestUnconstrainedDownloadsAsync(param::async_iterable<llm::OS::Networking::BackgroundTransfer::DownloadOperation> const& operations)
    {
        return impl::call_factory<BackgroundDownloader, IBackgroundDownloaderUserConsent>([&](IBackgroundDownloaderUserConsent const& f) { return f.RequestUnconstrainedDownloadsAsync(operations); });
    }
    inline BackgroundTransferCompletionGroup::BackgroundTransferCompletionGroup() :
        BackgroundTransferCompletionGroup(impl::call_factory_cast<BackgroundTransferCompletionGroup(*)(llm::OS::Foundation::IActivationFactory const&), BackgroundTransferCompletionGroup>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<BackgroundTransferCompletionGroup>(); }))
    {
    }
    inline BackgroundTransferContentPart::BackgroundTransferContentPart() :
        BackgroundTransferContentPart(impl::call_factory_cast<BackgroundTransferContentPart(*)(llm::OS::Foundation::IActivationFactory const&), BackgroundTransferContentPart>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<BackgroundTransferContentPart>(); }))
    {
    }
    inline BackgroundTransferContentPart::BackgroundTransferContentPart(param::hstring const& name) :
        BackgroundTransferContentPart(impl::call_factory<BackgroundTransferContentPart, IBackgroundTransferContentPartFactory>([&](IBackgroundTransferContentPartFactory const& f) { return f.CreateWithName(name); }))
    {
    }
    inline BackgroundTransferContentPart::BackgroundTransferContentPart(param::hstring const& name, param::hstring const& fileName) :
        BackgroundTransferContentPart(impl::call_factory<BackgroundTransferContentPart, IBackgroundTransferContentPartFactory>([&](IBackgroundTransferContentPartFactory const& f) { return f.CreateWithNameAndFileName(name, fileName); }))
    {
    }
    inline auto BackgroundTransferError::GetStatus(int32_t hresult)
    {
        return impl::call_factory<BackgroundTransferError, IBackgroundTransferErrorStaticMethods>([&](IBackgroundTransferErrorStaticMethods const& f) { return f.GetStatus(hresult); });
    }
    inline auto BackgroundTransferGroup::CreateGroup(param::hstring const& name)
    {
        return impl::call_factory<BackgroundTransferGroup, IBackgroundTransferGroupStatics>([&](IBackgroundTransferGroupStatics const& f) { return f.CreateGroup(name); });
    }
    inline BackgroundUploader::BackgroundUploader() :
        BackgroundUploader(impl::call_factory_cast<BackgroundUploader(*)(llm::OS::Foundation::IActivationFactory const&), BackgroundUploader>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<BackgroundUploader>(); }))
    {
    }
    inline BackgroundUploader::BackgroundUploader(llm::OS::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup const& completionGroup) :
        BackgroundUploader(impl::call_factory<BackgroundUploader, IBackgroundUploaderFactory>([&](IBackgroundUploaderFactory const& f) { return f.CreateWithCompletionGroup(completionGroup); }))
    {
    }
    inline auto BackgroundUploader::GetCurrentUploadsAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::BackgroundTransfer::UploadOperation>>(*)(IBackgroundUploaderStaticMethods const&), BackgroundUploader, IBackgroundUploaderStaticMethods>([](IBackgroundUploaderStaticMethods const& f) { return f.GetCurrentUploadsAsync(); });
    }
    inline auto BackgroundUploader::GetCurrentUploadsAsync(param::hstring const& group)
    {
        return impl::call_factory<BackgroundUploader, IBackgroundUploaderStaticMethods>([&](IBackgroundUploaderStaticMethods const& f) { return f.GetCurrentUploadsAsync(group); });
    }
    inline auto BackgroundUploader::GetCurrentUploadsForTransferGroupAsync(llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup const& group)
    {
        return impl::call_factory<BackgroundUploader, IBackgroundUploaderStaticMethods2>([&](IBackgroundUploaderStaticMethods2 const& f) { return f.GetCurrentUploadsForTransferGroupAsync(group); });
    }
    inline auto BackgroundUploader::RequestUnconstrainedUploadsAsync(param::async_iterable<llm::OS::Networking::BackgroundTransfer::UploadOperation> const& operations)
    {
        return impl::call_factory<BackgroundUploader, IBackgroundUploaderUserConsent>([&](IBackgroundUploaderUserConsent const& f) { return f.RequestUnconstrainedUploadsAsync(operations); });
    }
    inline auto ContentPrefetcher::ContentUris()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVector<llm::OS::Foundation::Uri>(*)(IContentPrefetcher const&), ContentPrefetcher, IContentPrefetcher>([](IContentPrefetcher const& f) { return f.ContentUris(); });
    }
    inline auto ContentPrefetcher::IndirectContentUri(llm::OS::Foundation::Uri const& value)
    {
        impl::call_factory<ContentPrefetcher, IContentPrefetcher>([&](IContentPrefetcher const& f) { return f.IndirectContentUri(value); });
    }
    inline auto ContentPrefetcher::IndirectContentUri()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Uri(*)(IContentPrefetcher const&), ContentPrefetcher, IContentPrefetcher>([](IContentPrefetcher const& f) { return f.IndirectContentUri(); });
    }
    inline auto ContentPrefetcher::LastSuccessfulPrefetchTime()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>(*)(IContentPrefetcherTime const&), ContentPrefetcher, IContentPrefetcherTime>([](IContentPrefetcherTime const& f) { return f.LastSuccessfulPrefetchTime(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundDownloader> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundDownloader2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundDownloader3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundDownloaderFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundDownloaderStaticMethods> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundDownloaderStaticMethods2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundDownloaderUserConsent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundTransferBase> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroupTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundTransferContentPart> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundTransferContentPartFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundTransferErrorStaticMethods> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundTransferGroup> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundTransferGroupStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundTransferOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundTransferOperationPriority> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundTransferRangesDownloadedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundUploader> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundUploader2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundUploader3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundUploaderFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundUploaderStaticMethods> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundUploaderStaticMethods2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IBackgroundUploaderUserConsent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IContentPrefetcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IContentPrefetcherTime> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IDownloadOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IDownloadOperation2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IDownloadOperation3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IDownloadOperation4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IDownloadOperation5> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IResponseInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IUnconstrainedTransferRequestResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IUploadOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IUploadOperation2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IUploadOperation3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::IUploadOperation4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::BackgroundDownloader> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::BackgroundTransferCompletionGroupTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::BackgroundTransferContentPart> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::BackgroundTransferError> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::BackgroundTransferGroup> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::BackgroundTransferRangesDownloadedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::BackgroundUploader> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::ContentPrefetcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::DownloadOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::ResponseInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::BackgroundTransfer::UploadOperation> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
