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
#ifndef LLM_OS_ApplicationModel_DataTransfer_1_H
#define LLM_OS_ApplicationModel_DataTransfer_1_H
#include "llm/impl/Windows.Foundation.Collections.0.h"
#include "llm/impl/Windows.ApplicationModel.DataTransfer.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::DataTransfer
{
    struct __declspec(empty_bases) IClipboardContentOptions :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClipboardContentOptions>
    {
        IClipboardContentOptions(std::nullptr_t = nullptr) noexcept {}
        IClipboardContentOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClipboardHistoryChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClipboardHistoryChangedEventArgs>
    {
        IClipboardHistoryChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IClipboardHistoryChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClipboardHistoryItem :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClipboardHistoryItem>
    {
        IClipboardHistoryItem(std::nullptr_t = nullptr) noexcept {}
        IClipboardHistoryItem(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClipboardHistoryItemsResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClipboardHistoryItemsResult>
    {
        IClipboardHistoryItemsResult(std::nullptr_t = nullptr) noexcept {}
        IClipboardHistoryItemsResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClipboardStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClipboardStatics>
    {
        IClipboardStatics(std::nullptr_t = nullptr) noexcept {}
        IClipboardStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClipboardStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IClipboardStatics2>
    {
        IClipboardStatics2(std::nullptr_t = nullptr) noexcept {}
        IClipboardStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataPackage :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataPackage>
    {
        IDataPackage(std::nullptr_t = nullptr) noexcept {}
        IDataPackage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataPackage2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataPackage2>
    {
        IDataPackage2(std::nullptr_t = nullptr) noexcept {}
        IDataPackage2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataPackage3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataPackage3>
    {
        IDataPackage3(std::nullptr_t = nullptr) noexcept {}
        IDataPackage3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataPackage4 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataPackage4>
    {
        IDataPackage4(std::nullptr_t = nullptr) noexcept {}
        IDataPackage4(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataPackagePropertySet :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataPackagePropertySet>,
        impl::require<llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet, llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::Foundation::IInspectable>>, llm::OS::Foundation::Collections::IMap<hstring, llm::OS::Foundation::IInspectable>>
    {
        IDataPackagePropertySet(std::nullptr_t = nullptr) noexcept {}
        IDataPackagePropertySet(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataPackagePropertySet2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataPackagePropertySet2>
    {
        IDataPackagePropertySet2(std::nullptr_t = nullptr) noexcept {}
        IDataPackagePropertySet2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataPackagePropertySet3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataPackagePropertySet3>
    {
        IDataPackagePropertySet3(std::nullptr_t = nullptr) noexcept {}
        IDataPackagePropertySet3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataPackagePropertySet4 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataPackagePropertySet4>
    {
        IDataPackagePropertySet4(std::nullptr_t = nullptr) noexcept {}
        IDataPackagePropertySet4(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataPackagePropertySetView :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataPackagePropertySetView>
    {
        IDataPackagePropertySetView(std::nullptr_t = nullptr) noexcept {}
        IDataPackagePropertySetView(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataPackagePropertySetView2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataPackagePropertySetView2>
    {
        IDataPackagePropertySetView2(std::nullptr_t = nullptr) noexcept {}
        IDataPackagePropertySetView2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataPackagePropertySetView3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataPackagePropertySetView3>
    {
        IDataPackagePropertySetView3(std::nullptr_t = nullptr) noexcept {}
        IDataPackagePropertySetView3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataPackagePropertySetView4 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataPackagePropertySetView4>
    {
        IDataPackagePropertySetView4(std::nullptr_t = nullptr) noexcept {}
        IDataPackagePropertySetView4(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataPackagePropertySetView5 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataPackagePropertySetView5>
    {
        IDataPackagePropertySetView5(std::nullptr_t = nullptr) noexcept {}
        IDataPackagePropertySetView5(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataPackageView :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataPackageView>
    {
        IDataPackageView(std::nullptr_t = nullptr) noexcept {}
        IDataPackageView(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataPackageView2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataPackageView2>
    {
        IDataPackageView2(std::nullptr_t = nullptr) noexcept {}
        IDataPackageView2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataPackageView3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataPackageView3>
    {
        IDataPackageView3(std::nullptr_t = nullptr) noexcept {}
        IDataPackageView3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataPackageView4 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataPackageView4>
    {
        IDataPackageView4(std::nullptr_t = nullptr) noexcept {}
        IDataPackageView4(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataProviderDeferral :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataProviderDeferral>
    {
        IDataProviderDeferral(std::nullptr_t = nullptr) noexcept {}
        IDataProviderDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataProviderRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataProviderRequest>
    {
        IDataProviderRequest(std::nullptr_t = nullptr) noexcept {}
        IDataProviderRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataRequest>
    {
        IDataRequest(std::nullptr_t = nullptr) noexcept {}
        IDataRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataRequestDeferral :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataRequestDeferral>
    {
        IDataRequestDeferral(std::nullptr_t = nullptr) noexcept {}
        IDataRequestDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataRequestedEventArgs>
    {
        IDataRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IDataRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataTransferManager :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataTransferManager>
    {
        IDataTransferManager(std::nullptr_t = nullptr) noexcept {}
        IDataTransferManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataTransferManager2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataTransferManager2>
    {
        IDataTransferManager2(std::nullptr_t = nullptr) noexcept {}
        IDataTransferManager2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataTransferManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataTransferManagerStatics>
    {
        IDataTransferManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IDataTransferManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataTransferManagerStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataTransferManagerStatics2>
    {
        IDataTransferManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        IDataTransferManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataTransferManagerStatics3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDataTransferManagerStatics3>
    {
        IDataTransferManagerStatics3(std::nullptr_t = nullptr) noexcept {}
        IDataTransferManagerStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHtmlFormatHelperStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHtmlFormatHelperStatics>
    {
        IHtmlFormatHelperStatics(std::nullptr_t = nullptr) noexcept {}
        IHtmlFormatHelperStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IOperationCompletedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IOperationCompletedEventArgs>
    {
        IOperationCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IOperationCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IOperationCompletedEventArgs2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IOperationCompletedEventArgs2>
    {
        IOperationCompletedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IOperationCompletedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IShareCompletedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IShareCompletedEventArgs>
    {
        IShareCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IShareCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IShareProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IShareProvider>
    {
        IShareProvider(std::nullptr_t = nullptr) noexcept {}
        IShareProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IShareProviderFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IShareProviderFactory>
    {
        IShareProviderFactory(std::nullptr_t = nullptr) noexcept {}
        IShareProviderFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IShareProviderOperation :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IShareProviderOperation>
    {
        IShareProviderOperation(std::nullptr_t = nullptr) noexcept {}
        IShareProviderOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IShareProvidersRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IShareProvidersRequestedEventArgs>
    {
        IShareProvidersRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IShareProvidersRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IShareTargetInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IShareTargetInfo>
    {
        IShareTargetInfo(std::nullptr_t = nullptr) noexcept {}
        IShareTargetInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IShareUIOptions :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IShareUIOptions>
    {
        IShareUIOptions(std::nullptr_t = nullptr) noexcept {}
        IShareUIOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISharedStorageAccessManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISharedStorageAccessManagerStatics>
    {
        ISharedStorageAccessManagerStatics(std::nullptr_t = nullptr) noexcept {}
        ISharedStorageAccessManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStandardDataFormatsStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStandardDataFormatsStatics>
    {
        IStandardDataFormatsStatics(std::nullptr_t = nullptr) noexcept {}
        IStandardDataFormatsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStandardDataFormatsStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStandardDataFormatsStatics2>
    {
        IStandardDataFormatsStatics2(std::nullptr_t = nullptr) noexcept {}
        IStandardDataFormatsStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStandardDataFormatsStatics3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStandardDataFormatsStatics3>
    {
        IStandardDataFormatsStatics3(std::nullptr_t = nullptr) noexcept {}
        IStandardDataFormatsStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITargetApplicationChosenEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITargetApplicationChosenEventArgs>
    {
        ITargetApplicationChosenEventArgs(std::nullptr_t = nullptr) noexcept {}
        ITargetApplicationChosenEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
