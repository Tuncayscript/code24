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
#ifndef LLM_OS_Networking_BackgroundTransfer_1_H
#define LLM_OS_Networking_BackgroundTransfer_1_H
#include "llm/impl/Windows.Networking.BackgroundTransfer.0.h"
LLM_EXPORT namespace llm:OS::Networking::BackgroundTransfer
{
    struct __declspec(empty_bases) IBackgroundDownloader :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundDownloader>,
        impl::require<llm:OS::Networking::BackgroundTransfer::IBackgroundDownloader, llm:OS::Networking::BackgroundTransfer::IBackgroundTransferBase>
    {
        IBackgroundDownloader(std::nullptr_t = nullptr) noexcept {}
        IBackgroundDownloader(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundDownloader2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundDownloader2>
    {
        IBackgroundDownloader2(std::nullptr_t = nullptr) noexcept {}
        IBackgroundDownloader2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundDownloader3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundDownloader3>
    {
        IBackgroundDownloader3(std::nullptr_t = nullptr) noexcept {}
        IBackgroundDownloader3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundDownloaderFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundDownloaderFactory>
    {
        IBackgroundDownloaderFactory(std::nullptr_t = nullptr) noexcept {}
        IBackgroundDownloaderFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundDownloaderStaticMethods :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundDownloaderStaticMethods>
    {
        IBackgroundDownloaderStaticMethods(std::nullptr_t = nullptr) noexcept {}
        IBackgroundDownloaderStaticMethods(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundDownloaderStaticMethods2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundDownloaderStaticMethods2>
    {
        IBackgroundDownloaderStaticMethods2(std::nullptr_t = nullptr) noexcept {}
        IBackgroundDownloaderStaticMethods2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundDownloaderUserConsent :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundDownloaderUserConsent>
    {
        IBackgroundDownloaderUserConsent(std::nullptr_t = nullptr) noexcept {}
        IBackgroundDownloaderUserConsent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTransferBase :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTransferBase>
    {
        IBackgroundTransferBase(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTransferBase(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTransferCompletionGroup :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTransferCompletionGroup>
    {
        IBackgroundTransferCompletionGroup(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTransferCompletionGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTransferCompletionGroupTriggerDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTransferCompletionGroupTriggerDetails>
    {
        IBackgroundTransferCompletionGroupTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTransferCompletionGroupTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTransferContentPart :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTransferContentPart>
    {
        IBackgroundTransferContentPart(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTransferContentPart(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTransferContentPartFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTransferContentPartFactory>
    {
        IBackgroundTransferContentPartFactory(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTransferContentPartFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTransferErrorStaticMethods :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTransferErrorStaticMethods>
    {
        IBackgroundTransferErrorStaticMethods(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTransferErrorStaticMethods(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTransferGroup :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTransferGroup>
    {
        IBackgroundTransferGroup(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTransferGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTransferGroupStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTransferGroupStatics>
    {
        IBackgroundTransferGroupStatics(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTransferGroupStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTransferOperation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTransferOperation>
    {
        IBackgroundTransferOperation(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTransferOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTransferOperationPriority :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTransferOperationPriority>
    {
        IBackgroundTransferOperationPriority(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTransferOperationPriority(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTransferRangesDownloadedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTransferRangesDownloadedEventArgs>
    {
        IBackgroundTransferRangesDownloadedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTransferRangesDownloadedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundUploader :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundUploader>,
        impl::require<llm:OS::Networking::BackgroundTransfer::IBackgroundUploader, llm:OS::Networking::BackgroundTransfer::IBackgroundTransferBase>
    {
        IBackgroundUploader(std::nullptr_t = nullptr) noexcept {}
        IBackgroundUploader(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundUploader2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundUploader2>
    {
        IBackgroundUploader2(std::nullptr_t = nullptr) noexcept {}
        IBackgroundUploader2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundUploader3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundUploader3>
    {
        IBackgroundUploader3(std::nullptr_t = nullptr) noexcept {}
        IBackgroundUploader3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundUploaderFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundUploaderFactory>
    {
        IBackgroundUploaderFactory(std::nullptr_t = nullptr) noexcept {}
        IBackgroundUploaderFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundUploaderStaticMethods :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundUploaderStaticMethods>
    {
        IBackgroundUploaderStaticMethods(std::nullptr_t = nullptr) noexcept {}
        IBackgroundUploaderStaticMethods(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundUploaderStaticMethods2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundUploaderStaticMethods2>
    {
        IBackgroundUploaderStaticMethods2(std::nullptr_t = nullptr) noexcept {}
        IBackgroundUploaderStaticMethods2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundUploaderUserConsent :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundUploaderUserConsent>
    {
        IBackgroundUploaderUserConsent(std::nullptr_t = nullptr) noexcept {}
        IBackgroundUploaderUserConsent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContentPrefetcher :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IContentPrefetcher>
    {
        IContentPrefetcher(std::nullptr_t = nullptr) noexcept {}
        IContentPrefetcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContentPrefetcherTime :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IContentPrefetcherTime>
    {
        IContentPrefetcherTime(std::nullptr_t = nullptr) noexcept {}
        IContentPrefetcherTime(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDownloadOperation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDownloadOperation>,
        impl::require<llm:OS::Networking::BackgroundTransfer::IDownloadOperation, llm:OS::Networking::BackgroundTransfer::IBackgroundTransferOperation>
    {
        IDownloadOperation(std::nullptr_t = nullptr) noexcept {}
        IDownloadOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDownloadOperation2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDownloadOperation2>
    {
        IDownloadOperation2(std::nullptr_t = nullptr) noexcept {}
        IDownloadOperation2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDownloadOperation3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDownloadOperation3>
    {
        IDownloadOperation3(std::nullptr_t = nullptr) noexcept {}
        IDownloadOperation3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDownloadOperation4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDownloadOperation4>
    {
        IDownloadOperation4(std::nullptr_t = nullptr) noexcept {}
        IDownloadOperation4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDownloadOperation5 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDownloadOperation5>
    {
        IDownloadOperation5(std::nullptr_t = nullptr) noexcept {}
        IDownloadOperation5(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IResponseInformation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IResponseInformation>
    {
        IResponseInformation(std::nullptr_t = nullptr) noexcept {}
        IResponseInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUnconstrainedTransferRequestResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUnconstrainedTransferRequestResult>
    {
        IUnconstrainedTransferRequestResult(std::nullptr_t = nullptr) noexcept {}
        IUnconstrainedTransferRequestResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUploadOperation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUploadOperation>,
        impl::require<llm:OS::Networking::BackgroundTransfer::IUploadOperation, llm:OS::Networking::BackgroundTransfer::IBackgroundTransferOperation>
    {
        IUploadOperation(std::nullptr_t = nullptr) noexcept {}
        IUploadOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUploadOperation2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUploadOperation2>
    {
        IUploadOperation2(std::nullptr_t = nullptr) noexcept {}
        IUploadOperation2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUploadOperation3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUploadOperation3>
    {
        IUploadOperation3(std::nullptr_t = nullptr) noexcept {}
        IUploadOperation3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUploadOperation4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUploadOperation4>
    {
        IUploadOperation4(std::nullptr_t = nullptr) noexcept {}
        IUploadOperation4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
