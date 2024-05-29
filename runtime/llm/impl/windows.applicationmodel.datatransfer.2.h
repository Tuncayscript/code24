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
#ifndef LLM_OS_ApplicationModel_DataTransfer_2_H
#define LLM_OS_ApplicationModel_DataTransfer_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Storage.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.UI.1.h"
#include "llm/impl/Windows.ApplicationModel.DataTransfer.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::DataTransfer
{
    struct DataProviderHandler : llm::OS::Foundation::IUnknown
    {
        DataProviderHandler(std::nullptr_t = nullptr) noexcept {}
        DataProviderHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> DataProviderHandler(L lambda);
        template <typename F> DataProviderHandler(F* function);
        template <typename O, typename M> DataProviderHandler(O* object, M method);
        template <typename O, typename M> DataProviderHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> DataProviderHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::ApplicationModel::DataTransfer::DataProviderRequest const& request) const;
    };
    struct ShareProviderHandler : llm::OS::Foundation::IUnknown
    {
        ShareProviderHandler(std::nullptr_t = nullptr) noexcept {}
        ShareProviderHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> ShareProviderHandler(L lambda);
        template <typename F> ShareProviderHandler(F* function);
        template <typename O, typename M> ShareProviderHandler(O* object, M method);
        template <typename O, typename M> ShareProviderHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> ShareProviderHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::ApplicationModel::DataTransfer::ShareProviderOperation const& operation) const;
    };
    struct Clipboard
    {
        Clipboard() = delete;
        static auto GetContent();
        static auto SetContent(llm::OS::ApplicationModel::DataTransfer::DataPackage const& content);
        static auto Flush();
        static auto Clear();
        static auto ContentChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler);
        using ContentChanged_revoker = impl::factory_event_revoker<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics, &impl::abi_t<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics>::remove_ContentChanged>;
        [[nodiscard]] static ContentChanged_revoker ContentChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler);
        static auto ContentChanged(llm::event_token const& token);
        static auto GetHistoryItemsAsync();
        static auto ClearHistory();
        static auto DeleteItemFromHistory(llm::OS::ApplicationModel::DataTransfer::ClipboardHistoryItem const& item);
        static auto SetHistoryItemAsContent(llm::OS::ApplicationModel::DataTransfer::ClipboardHistoryItem const& item);
        static auto IsHistoryEnabled();
        static auto IsRoamingEnabled();
        static auto SetContentWithOptions(llm::OS::ApplicationModel::DataTransfer::DataPackage const& content, llm::OS::ApplicationModel::DataTransfer::ClipboardContentOptions const& options);
        static auto HistoryChanged(llm::OS::Foundation::EventHandler<llm::OS::ApplicationModel::DataTransfer::ClipboardHistoryChangedEventArgs> const& handler);
        using HistoryChanged_revoker = impl::factory_event_revoker<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics2, &impl::abi_t<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics2>::remove_HistoryChanged>;
        [[nodiscard]] static HistoryChanged_revoker HistoryChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::ApplicationModel::DataTransfer::ClipboardHistoryChangedEventArgs> const& handler);
        static auto HistoryChanged(llm::event_token const& token);
        static auto RoamingEnabledChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler);
        using RoamingEnabledChanged_revoker = impl::factory_event_revoker<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics2, &impl::abi_t<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics2>::remove_RoamingEnabledChanged>;
        [[nodiscard]] static RoamingEnabledChanged_revoker RoamingEnabledChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler);
        static auto RoamingEnabledChanged(llm::event_token const& token);
        static auto HistoryEnabledChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler);
        using HistoryEnabledChanged_revoker = impl::factory_event_revoker<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics2, &impl::abi_t<llm::OS::ApplicationModel::DataTransfer::IClipboardStatics2>::remove_HistoryEnabledChanged>;
        [[nodiscard]] static HistoryEnabledChanged_revoker HistoryEnabledChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler);
        static auto HistoryEnabledChanged(llm::event_token const& token);
    };
    struct __declspec(empty_bases) ClipboardContentOptions : llm::OS::ApplicationModel::DataTransfer::IClipboardContentOptions
    {
        ClipboardContentOptions(std::nullptr_t) noexcept {}
        ClipboardContentOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::IClipboardContentOptions(ptr, take_ownership_from_abi) {}
        ClipboardContentOptions();
    };
    struct __declspec(empty_bases) ClipboardHistoryChangedEventArgs : llm::OS::ApplicationModel::DataTransfer::IClipboardHistoryChangedEventArgs
    {
        ClipboardHistoryChangedEventArgs(std::nullptr_t) noexcept {}
        ClipboardHistoryChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::IClipboardHistoryChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ClipboardHistoryItem : llm::OS::ApplicationModel::DataTransfer::IClipboardHistoryItem
    {
        ClipboardHistoryItem(std::nullptr_t) noexcept {}
        ClipboardHistoryItem(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::IClipboardHistoryItem(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ClipboardHistoryItemsResult : llm::OS::ApplicationModel::DataTransfer::IClipboardHistoryItemsResult
    {
        ClipboardHistoryItemsResult(std::nullptr_t) noexcept {}
        ClipboardHistoryItemsResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::IClipboardHistoryItemsResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DataPackage : llm::OS::ApplicationModel::DataTransfer::IDataPackage,
        impl::require<DataPackage, llm::OS::ApplicationModel::DataTransfer::IDataPackage2, llm::OS::ApplicationModel::DataTransfer::IDataPackage3, llm::OS::ApplicationModel::DataTransfer::IDataPackage4>
    {
        DataPackage(std::nullptr_t) noexcept {}
        DataPackage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::IDataPackage(ptr, take_ownership_from_abi) {}
        DataPackage();
    };
    struct __declspec(empty_bases) DataPackagePropertySet : llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet,
        impl::require<DataPackagePropertySet, llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet2, llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet3, llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet4>
    {
        DataPackagePropertySet(std::nullptr_t) noexcept {}
        DataPackagePropertySet(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySet(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DataPackagePropertySetView : llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView,
        impl::require<DataPackagePropertySetView, llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView2, llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView3, llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView4, llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView5, llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::Foundation::IInspectable>>, llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>>
    {
        DataPackagePropertySetView(std::nullptr_t) noexcept {}
        DataPackagePropertySetView(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::IDataPackagePropertySetView(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DataPackageView : llm::OS::ApplicationModel::DataTransfer::IDataPackageView,
        impl::require<DataPackageView, llm::OS::ApplicationModel::DataTransfer::IDataPackageView2, llm::OS::ApplicationModel::DataTransfer::IDataPackageView3, llm::OS::ApplicationModel::DataTransfer::IDataPackageView4>
    {
        DataPackageView(std::nullptr_t) noexcept {}
        DataPackageView(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::IDataPackageView(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DataProviderDeferral : llm::OS::ApplicationModel::DataTransfer::IDataProviderDeferral
    {
        DataProviderDeferral(std::nullptr_t) noexcept {}
        DataProviderDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::IDataProviderDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DataProviderRequest : llm::OS::ApplicationModel::DataTransfer::IDataProviderRequest
    {
        DataProviderRequest(std::nullptr_t) noexcept {}
        DataProviderRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::IDataProviderRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DataRequest : llm::OS::ApplicationModel::DataTransfer::IDataRequest
    {
        DataRequest(std::nullptr_t) noexcept {}
        DataRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::IDataRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DataRequestDeferral : llm::OS::ApplicationModel::DataTransfer::IDataRequestDeferral
    {
        DataRequestDeferral(std::nullptr_t) noexcept {}
        DataRequestDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::IDataRequestDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DataRequestedEventArgs : llm::OS::ApplicationModel::DataTransfer::IDataRequestedEventArgs
    {
        DataRequestedEventArgs(std::nullptr_t) noexcept {}
        DataRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::IDataRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DataTransferManager : llm::OS::ApplicationModel::DataTransfer::IDataTransferManager,
        impl::require<DataTransferManager, llm::OS::ApplicationModel::DataTransfer::IDataTransferManager2>
    {
        DataTransferManager(std::nullptr_t) noexcept {}
        DataTransferManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::IDataTransferManager(ptr, take_ownership_from_abi) {}
        static auto ShowShareUI();
        static auto GetForCurrentView();
        static auto IsSupported();
        static auto ShowShareUI(llm::OS::ApplicationModel::DataTransfer::ShareUIOptions const& options);
    };
    struct HtmlFormatHelper
    {
        HtmlFormatHelper() = delete;
        static auto GetStaticFragment(param::hstring const& htmlFormat);
        static auto CreateHtmlFormat(param::hstring const& htmlFragment);
    };
    struct __declspec(empty_bases) OperationCompletedEventArgs : llm::OS::ApplicationModel::DataTransfer::IOperationCompletedEventArgs,
        impl::require<OperationCompletedEventArgs, llm::OS::ApplicationModel::DataTransfer::IOperationCompletedEventArgs2>
    {
        OperationCompletedEventArgs(std::nullptr_t) noexcept {}
        OperationCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::IOperationCompletedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ShareCompletedEventArgs : llm::OS::ApplicationModel::DataTransfer::IShareCompletedEventArgs
    {
        ShareCompletedEventArgs(std::nullptr_t) noexcept {}
        ShareCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::IShareCompletedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ShareProvider : llm::OS::ApplicationModel::DataTransfer::IShareProvider
    {
        ShareProvider(std::nullptr_t) noexcept {}
        ShareProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::IShareProvider(ptr, take_ownership_from_abi) {}
        ShareProvider(param::hstring const& title, llm::OS::Storage::Streams::RandomAccessStreamReference const& displayIcon, llm::OS::UI::Color const& backgroundColor, llm::OS::ApplicationModel::DataTransfer::ShareProviderHandler const& handler);
    };
    struct __declspec(empty_bases) ShareProviderOperation : llm::OS::ApplicationModel::DataTransfer::IShareProviderOperation
    {
        ShareProviderOperation(std::nullptr_t) noexcept {}
        ShareProviderOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::IShareProviderOperation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ShareProvidersRequestedEventArgs : llm::OS::ApplicationModel::DataTransfer::IShareProvidersRequestedEventArgs
    {
        ShareProvidersRequestedEventArgs(std::nullptr_t) noexcept {}
        ShareProvidersRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::IShareProvidersRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ShareTargetInfo : llm::OS::ApplicationModel::DataTransfer::IShareTargetInfo
    {
        ShareTargetInfo(std::nullptr_t) noexcept {}
        ShareTargetInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::IShareTargetInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ShareUIOptions : llm::OS::ApplicationModel::DataTransfer::IShareUIOptions
    {
        ShareUIOptions(std::nullptr_t) noexcept {}
        ShareUIOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::IShareUIOptions(ptr, take_ownership_from_abi) {}
        ShareUIOptions();
    };
    struct SharedStorageAccessManager
    {
        SharedStorageAccessManager() = delete;
        static auto AddFile(llm::OS::Storage::IStorageFile const& file);
        static auto RedeemTokenForFileAsync(param::hstring const& token);
        static auto RemoveFile(param::hstring const& token);
    };
    struct StandardDataFormats
    {
        StandardDataFormats() = delete;
        [[nodiscard]] static auto Text();
        [[nodiscard]] static auto Uri();
        [[nodiscard]] static auto Html();
        [[nodiscard]] static auto Rtf();
        [[nodiscard]] static auto Bitmap();
        [[nodiscard]] static auto StorageItems();
        [[nodiscard]] static auto WebLink();
        [[nodiscard]] static auto ApplicationLink();
        [[nodiscard]] static auto UserActivityJsonArray();
    };
    struct __declspec(empty_bases) TargetApplicationChosenEventArgs : llm::OS::ApplicationModel::DataTransfer::ITargetApplicationChosenEventArgs
    {
        TargetApplicationChosenEventArgs(std::nullptr_t) noexcept {}
        TargetApplicationChosenEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::ITargetApplicationChosenEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
