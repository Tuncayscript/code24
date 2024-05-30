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
#ifndef LLM_OS_Networking_BackgroundTransfer_2_H
#define LLM_OS_Networking_BackgroundTransfer_2_H
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Networking.BackgroundTransfer.1.h"
LLM_EXPORT namespace llm:OS::Networking::BackgroundTransfer
{
    struct BackgroundDownloadProgress
    {
        uint64_t BytesReceived;
        uint64_t TotalBytesToReceive;
        llm:OS::Networking::BackgroundTransfer::BackgroundTransferStatus Status;
        bool HasResponseChanged;
        bool HasRestarted;
    };
    inline bool operator==(BackgroundDownloadProgress const& left, BackgroundDownloadProgress const& right) noexcept
    {
        return left.BytesReceived == right.BytesReceived && left.TotalBytesToReceive == right.TotalBytesToReceive && left.Status == right.Status && left.HasResponseChanged == right.HasResponseChanged && left.HasRestarted == right.HasRestarted;
    }
    inline bool operator!=(BackgroundDownloadProgress const& left, BackgroundDownloadProgress const& right) noexcept
    {
        return !(left == right);
    }
    struct BackgroundTransferFileRange
    {
        uint64_t Offset;
        uint64_t Length;
    };
    inline bool operator==(BackgroundTransferFileRange const& left, BackgroundTransferFileRange const& right) noexcept
    {
        return left.Offset == right.Offset && left.Length == right.Length;
    }
    inline bool operator!=(BackgroundTransferFileRange const& left, BackgroundTransferFileRange const& right) noexcept
    {
        return !(left == right);
    }
    struct BackgroundUploadProgress
    {
        uint64_t BytesReceived;
        uint64_t BytesSent;
        uint64_t TotalBytesToReceive;
        uint64_t TotalBytesToSend;
        llm:OS::Networking::BackgroundTransfer::BackgroundTransferStatus Status;
        bool HasResponseChanged;
        bool HasRestarted;
    };
    inline bool operator==(BackgroundUploadProgress const& left, BackgroundUploadProgress const& right) noexcept
    {
        return left.BytesReceived == right.BytesReceived && left.BytesSent == right.BytesSent && left.TotalBytesToReceive == right.TotalBytesToReceive && left.TotalBytesToSend == right.TotalBytesToSend && left.Status == right.Status && left.HasResponseChanged == right.HasResponseChanged && left.HasRestarted == right.HasRestarted;
    }
    inline bool operator!=(BackgroundUploadProgress const& left, BackgroundUploadProgress const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) BackgroundDownloader : llm:OS::Networking::BackgroundTransfer::IBackgroundDownloader,
        impl::require<BackgroundDownloader, llm:OS::Networking::BackgroundTransfer::IBackgroundDownloader2, llm:OS::Networking::BackgroundTransfer::IBackgroundDownloader3>
    {
        BackgroundDownloader(std::nullptr_t) noexcept {}
        BackgroundDownloader(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::BackgroundTransfer::IBackgroundDownloader(ptr, take_ownership_from_abi) {}
        BackgroundDownloader();
        explicit BackgroundDownloader(llm:OS::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup const& completionGroup);
        static auto GetCurrentDownloadsAsync();
        static auto GetCurrentDownloadsAsync(param::hstring const& group);
        static auto GetCurrentDownloadsForTransferGroupAsync(llm:OS::Networking::BackgroundTransfer::BackgroundTransferGroup const& group);
        static auto RequestUnconstrainedDownloadsAsync(param::async_iterable<llm:OS::Networking::BackgroundTransfer::DownloadOperation> const& operations);
    };
    struct __declspec(empty_bases) BackgroundTransferCompletionGroup : llm:OS::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup
    {
        BackgroundTransferCompletionGroup(std::nullptr_t) noexcept {}
        BackgroundTransferCompletionGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup(ptr, take_ownership_from_abi) {}
        BackgroundTransferCompletionGroup();
    };
    struct __declspec(empty_bases) BackgroundTransferCompletionGroupTriggerDetails : llm:OS::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroupTriggerDetails
    {
        BackgroundTransferCompletionGroupTriggerDetails(std::nullptr_t) noexcept {}
        BackgroundTransferCompletionGroupTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroupTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BackgroundTransferContentPart : llm:OS::Networking::BackgroundTransfer::IBackgroundTransferContentPart
    {
        BackgroundTransferContentPart(std::nullptr_t) noexcept {}
        BackgroundTransferContentPart(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::BackgroundTransfer::IBackgroundTransferContentPart(ptr, take_ownership_from_abi) {}
        BackgroundTransferContentPart();
        explicit BackgroundTransferContentPart(param::hstring const& name);
        BackgroundTransferContentPart(param::hstring const& name, param::hstring const& fileName);
    };
    struct BackgroundTransferError
    {
        BackgroundTransferError() = delete;
        static auto GetStatus(int32_t hresult);
    };
    struct __declspec(empty_bases) BackgroundTransferGroup : llm:OS::Networking::BackgroundTransfer::IBackgroundTransferGroup
    {
        BackgroundTransferGroup(std::nullptr_t) noexcept {}
        BackgroundTransferGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::BackgroundTransfer::IBackgroundTransferGroup(ptr, take_ownership_from_abi) {}
        static auto CreateGroup(param::hstring const& name);
    };
    struct __declspec(empty_bases) BackgroundTransferRangesDownloadedEventArgs : llm:OS::Networking::BackgroundTransfer::IBackgroundTransferRangesDownloadedEventArgs
    {
        BackgroundTransferRangesDownloadedEventArgs(std::nullptr_t) noexcept {}
        BackgroundTransferRangesDownloadedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::BackgroundTransfer::IBackgroundTransferRangesDownloadedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BackgroundUploader : llm:OS::Networking::BackgroundTransfer::IBackgroundUploader,
        impl::require<BackgroundUploader, llm:OS::Networking::BackgroundTransfer::IBackgroundUploader2, llm:OS::Networking::BackgroundTransfer::IBackgroundUploader3>
    {
        BackgroundUploader(std::nullptr_t) noexcept {}
        BackgroundUploader(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::BackgroundTransfer::IBackgroundUploader(ptr, take_ownership_from_abi) {}
        BackgroundUploader();
        explicit BackgroundUploader(llm:OS::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup const& completionGroup);
        static auto GetCurrentUploadsAsync();
        static auto GetCurrentUploadsAsync(param::hstring const& group);
        static auto GetCurrentUploadsForTransferGroupAsync(llm:OS::Networking::BackgroundTransfer::BackgroundTransferGroup const& group);
        static auto RequestUnconstrainedUploadsAsync(param::async_iterable<llm:OS::Networking::BackgroundTransfer::UploadOperation> const& operations);
    };
    struct ContentPrefetcher
    {
        ContentPrefetcher() = delete;
        [[nodiscard]] static auto ContentUris();
        static auto IndirectContentUri(llm:OS::Foundation::Uri const& value);
        [[nodiscard]] static auto IndirectContentUri();
        [[nodiscard]] static auto LastSuccessfulPrefetchTime();
    };
    struct __declspec(empty_bases) DownloadOperation : llm:OS::Networking::BackgroundTransfer::IDownloadOperation,
        impl::require<DownloadOperation, llm:OS::Networking::BackgroundTransfer::IBackgroundTransferOperationPriority, llm:OS::Networking::BackgroundTransfer::IDownloadOperation2, llm:OS::Networking::BackgroundTransfer::IDownloadOperation3, llm:OS::Networking::BackgroundTransfer::IDownloadOperation4, llm:OS::Networking::BackgroundTransfer::IDownloadOperation5>
    {
        DownloadOperation(std::nullptr_t) noexcept {}
        DownloadOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::BackgroundTransfer::IDownloadOperation(ptr, take_ownership_from_abi) {}
        using llm:OS::Networking::BackgroundTransfer::IDownloadOperation::RequestedUri;
        using impl::consume_t<DownloadOperation, llm:OS::Networking::BackgroundTransfer::IDownloadOperation3>::RequestedUri;
    };
    struct __declspec(empty_bases) ResponseInformation : llm:OS::Networking::BackgroundTransfer::IResponseInformation
    {
        ResponseInformation(std::nullptr_t) noexcept {}
        ResponseInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::BackgroundTransfer::IResponseInformation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UnconstrainedTransferRequestResult : llm:OS::Networking::BackgroundTransfer::IUnconstrainedTransferRequestResult
    {
        UnconstrainedTransferRequestResult(std::nullptr_t) noexcept {}
        UnconstrainedTransferRequestResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::BackgroundTransfer::IUnconstrainedTransferRequestResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UploadOperation : llm:OS::Networking::BackgroundTransfer::IUploadOperation,
        impl::require<UploadOperation, llm:OS::Networking::BackgroundTransfer::IBackgroundTransferOperationPriority, llm:OS::Networking::BackgroundTransfer::IUploadOperation2, llm:OS::Networking::BackgroundTransfer::IUploadOperation3, llm:OS::Networking::BackgroundTransfer::IUploadOperation4>
    {
        UploadOperation(std::nullptr_t) noexcept {}
        UploadOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::BackgroundTransfer::IUploadOperation(ptr, take_ownership_from_abi) {}
    };
}
#endif
